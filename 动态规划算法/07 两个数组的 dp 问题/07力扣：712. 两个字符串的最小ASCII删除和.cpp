// 力扣：712. 两个字符串的最小ASCII删除和
// 链接：https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/description/

// 方法：动态规划
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();

        // dp[i][j] 表示 s1[0...i] 和 s2[0...j] 的最大公共子序列 ASCII 值之和
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 计算 dp[i][j]，用于求最大公共子序列的 ASCII 值之和
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);     // 继承前面最大值，避免删除过多字符

                // 若 s1[i-1] == s2[j-1]，则可增加公共子序列的 ASCII 值
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s1[i - 1]);
                    // dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + s2[j - 1]);
                }
            }
        }

        // 计算 s1 和 s2 的总 ASCII 值
        int sum = 0;
        for (char x : s1)
        {
            sum += x;
        }
        for (char x : s2)
        {
            sum += x;
        }

        return sum - dp[m][n] * 2;                              // 总 ASCII 值减去两倍的最大公共子序列 ASCII 值，得到最小删除和
    }
};