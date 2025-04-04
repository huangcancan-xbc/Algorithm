// 力扣：1143. 最长公共子序列
// 链接：https://leetcode.cn/problems/longest-common-subsequence/description/

// 方法：动态规划
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        // dp[i][j] 表示 text1 的前 i 个字符和 text2 的前 j 个字符所具有的最长公共子序列的长度
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // 遍历整个 dp 数组，通过动态规划求解
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 如果 text1[i-1] 与 text2[j-1] 相等，即两个字符串结尾字符相同，
                // 那么这一定是目前的最长公共子序列，长度等于前一个状态 dp[i-1][j-1] + 1
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    // 如果两个字符不相等，最长公共子序列只能结尾字符开始往前找，即（text1 的前 i - 1 个字符和 text2 的
                    // 前 j 个字符）和（text1 的前 i 个字符和 text2 的前 j - 1 个字符）所具有的最长公共子序列的长度的较大值
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];                // 最终结果存储在 dp[n][m]，表示 text1 和 text2 的最长公共子序列的长度
    }
};


// 空串的优势：在字符串前添加一个空串（空格等）可以帮助我们处理边界条件，使得算法更加简单。
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        text1 = " " + text1, text2 = " " + text2;   // 增加空格，方便处理边界条件
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i] == text2[j])           // 这里就不必再考虑下标映射关系了
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};