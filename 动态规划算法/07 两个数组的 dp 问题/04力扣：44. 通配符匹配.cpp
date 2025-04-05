// 力扣：44. 通配符匹配
// 链接：https://leetcode.cn/problems/wildcard-matching/description/

// 方法：动态规划
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();                     // 获取字符串 s 和模式串 p 的长度
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));// 创建 dp 数组，dp[i][j] 表示 s 的前 i 个字符是否能与 p 的前 j 个字符匹配
        dp[0][0] = true;                                    // 初始化 dp[0][0]，空字符串与空模式匹配

        // 处理模式串 p 的第一个字符是 '*' 的情况
        // 如果 p 的前 j 个字符是 '*'，则空字符串可以匹配这些 '*'（即 dp[0][j] = true）
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];                    // 只有 '*' 才可以匹配空字符串
            }
            else
            {
                break;                                      // 一旦遇到非 '*' 的字符，空字符串就无法匹配后面的模式
            }
        }

        // 填充 dp 数组，遍历每个字符 s[i-1] 和 p[j-1]
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')                        // 如果当前模式字符是 '*'
                {
                    // '*' 可以匹配 0 个或多个字符，因此我们查看：
                    // 1. 不匹配当前字符，即 dp[i][j-1]（表示 '*' 不匹配当前字符）
                    // 2. 匹配一个字符，即 dp[i-1][j]（表示 '*' 匹配当前字符）
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    // 如果模式字符是 '?'，或者当前字符 s[i-1] 与模式字符 p[j-1] 相同，则可以继续向前匹配，查看之前的状态 dp[i-1][j-1]
                    dp[i][j] = ((p[j - 1] == '?' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];                                    // 返回最终的匹配结果，dp[m][n] 表示整个字符串 s 是否能匹配整个模式串 p
    }
};


// 添加空串避免边界条件
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        s = " " + s, p = " " + p;                           // 在 s 和 p 前面添加空格，避免边界条件
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        dp[0][0] = true;
        for (int j = 1; j <= n; j++)
        {
            if (p[j] == '*')
            {
                dp[0][j] = true;
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = ((p[j] == '?' || s[i] == p[j]) && dp[i - 1][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};