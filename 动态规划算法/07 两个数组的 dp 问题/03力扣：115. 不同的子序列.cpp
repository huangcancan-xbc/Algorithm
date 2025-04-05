// 力扣：115. 不同的子序列
// 链接：https://leetcode.cn/problems/distinct-subsequences/description/

// 方法：动态规划
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        const int MOD = 1e9 + 7;                // 定义常量MOD用于取模，防止结果溢出
        int n = s.size(), m = t.size();         // 获取两个字符串的长度

        // 定义二维dp数组，dp[i][j]表示考虑s的前i个字符和t的前j个字符时，不同子序列的数量
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        // 初始化第一列，表示当t为空时，s的任何子序列都可以匹配t（即只有1种方法：空子序列）
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // 动态规划填充dp数组
        for (int i = 1; i <= n; i++)            // 遍历s的每个字符
        {
            for (int j = 1; j <= m; j++)        // 遍历t的每个字符
            {
                if (s[i - 1] == t[j - 1])       // 如果s和t当前字符相等
                {
                    // 可以选择不匹配当前字符，或者选择匹配当前字符
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else                            // 如果s和t当前字符不相等
                {
                    // 只能选择不匹配当前字符
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[n][m];                        // 最终结果是dp[n][m]，即考虑s的前n个字符和t的前m个字符时，不同子序列的数量
    }
};

// 使用添加空串避免边界条件的优化
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        const int MOD = 1e9 + 7;
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        s = " " + s, t = " " + t;           // 添加空串避免边界条件
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i] == t[j])           // 不必考虑下标映射问题
                {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[n][m];
    }
};