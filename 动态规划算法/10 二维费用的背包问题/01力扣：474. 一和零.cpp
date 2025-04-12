// 力扣：474. 一和零
// 链接：https://leetcode.cn/problems/ones-and-zeroes/description/

// 方法：动态规划（0-1 背包问题变形）
class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int len = strs.size();                      // 获取字符串数组的长度
        // 定义三维 DP 数组，dp[i][j][k] 表示在前 i 个字符串中，使用最多 j 个 '0' 和 k 个 '1' 时的最大子集大小
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

        // 遍历每个字符串，进行状态转移
        for (int i = 1; i <= len; i++)
        {
            int a = 0, b = 0;                       // 统计当前字符串中 '0' 和 '1' 的个数
            for (auto x : strs[i - 1])
            {
                if (x == '0')
                {
                    a++;                            // 统计 '0' 的个数
                }
                else
                {
                    b++;                            // 统计 '1' 的个数
                }
            }

            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];  // 默认不选择当前字符串
                    if (j >= a && k >= b)           // 如果当前字符串的 '0' 和 '1' 数量都满足要求，则可以选择它
                    {
                        // 状态转移方程：选择当前字符串或不选，取最大值
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - a][k - b] + 1);
                    }
                }
            }

        }

        return dp[len][m][n];                       // 返回最多可以构成的子集数量
    }
};


// 空间优化：只用到二维 DP 数组，不用三维 DP 数组
class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        int len = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= len; i++)
        {
            int a = 0, b = 0;
            for (auto x : strs[i - 1])
            {
                if (x == '0')
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }

            // 采用倒序遍历，确保状态转移时不会影响之前的计算结果
            for (int j = m; j >= a; j--)
            {
                for (int k = n; k >= b; k--)
                {
                    dp[j][k] = max(dp[j][k], dp[j - a][k - b] + 1);

                }
            }
        }

        return dp[m][n];
    }
};