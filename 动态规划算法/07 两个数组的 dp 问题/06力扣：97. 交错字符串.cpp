// 力扣：97. 交错字符串
// 链接：https://leetcode.cn/problems/interleaving-string/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
        {
            return false;                           // 若 s1 和 s2 的长度之和不等于 s3，则必定无法交错形成 s3
        }
        s1 = " " + s1, s2 = " " + s2, s3 = " " + s3;// 在字符串开头添加空格，方便处理边界情况

        // dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否可以交错形成 s3 的前 (i+j) 个字符
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;                            // 空字符串匹配空字符串

        // 处理第一行，即 s1 为空，只能由 s2 形成 s3
        for (int j = 1; j <= n; j++)
        {
            if (s2[j] == s3[j])
            {
                dp[0][j] = dp[0][j - 1];            // 继承前一状态
            }
            else
            {
                break;                              // 遇到不匹配的字符，后续都无法匹配
            }
        }
        // 处理第一列，即 s2 为空，只能由 s1 形成 s3
        for (int i = 1; i <= m; i++)
        {
            if (s1[i] == s3[i])
            {
                dp[i][0] = dp[i - 1][0];            // 继承前一状态
            }
            else
            {
                break;                              // 遇到不匹配的字符，后续都无法匹配
            }
        }

        // 计算 dp[i][j]，即 s1[1...i] 和 s2[1...j] 是否可以形成 s3[1...i+j]
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 当前 s3[i+j] 可能来自 s1[i] 或 s2[j]
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);
            }
        }

        return dp[m][n];                            // 返回 s1 和 s2 是否能交错形成 s3
    }
};