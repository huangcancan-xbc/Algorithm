// 力扣：10. 正则表达式匹配
// 链接：https://leetcode.cn/problems/regular-expression-matching/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        s = " " + s, p = " " + p;                       // 在字符串开头添加空格，方便处理边界情况

        // dp[i][j] 表示 s 的前 i 个字符（0到i）与 p 的前 j 个字符（0到j）是否匹配
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;                                // 空字符串匹配空模式就是true

        // 初始化。处理模式串 p 以 '*' 结尾的情况，例如 "a*", "a*b*", ".*" 等
        for (int j = 2; j <= n; j += 2)
        {
            if (p[j] == '*')
            {
                dp[0][j] = dp[0][j - 2];                // '*' 可以让前一个字符出现 0 次
            }
            else
            {
                break;                                  // 如果不是 '*'，则无法继续匹配空字符串，退出循环
            }
        }

        // 状态转移
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j] == '*')
                {
                    // '*' 代表前一个字符可以出现 0 次或多次
                    // 1. dp[i][j - 2]：'*' 让 p[j-1] 出现 0 次，相当于用空串--删除 "x*" 这两个字符
                    // 2. (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j]：'*' 让 p[j-1] 重复多次，s[i] 和 p[j-1] 匹配，则继续向前匹配 s[i-1] 和 p[j]
                    dp[i][j] = dp[i][j - 2] || ((p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j]);
                }
                else
                {
                    // 普通字符匹配：只有当前字符相等或 p[j] 是 '.' 时，才能延续前面的匹配状态
                    dp[i][j] = (p[j] == s[i] || p[j] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];                                // 返回 s[1...m] 与 p[1...n] 的匹配结果（由于第一个字符是空格，dp[0...m][0...n]也对）
    }
};


// 不使用空串，考虑边界情况：
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;

        for (int j = 2; j <= n; j += 2)
        {
            if (p[j - 1] == '*')
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
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = (p[j - 1] == s[i - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};