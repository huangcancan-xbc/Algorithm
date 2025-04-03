// 力扣：1312. 让字符串成为回文串的最少插入次数
// 链接：https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// 方法：动态规划
class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();                                   // 获取字符串长度
        
        vector<vector<int>> dp(n, vector<int>(n, 0));       // dp[i][j] 表示将子字符串 s[i...j] 转换为回文串所需的最少插入次数

        
        for (int i = n - 1; i >= 0; i--)                    // 从后往前遍历所有子串
        {
            dp[i][i] = 0;                                   // 单个字符的子串已经是回文串，不需要插入

            for (int j = i + 1; j < n; j++)                 // 遍历每个可能的子串 [i, j]
            {
                // 如果 s[i] == s[j]，表示这两个字符已经是回文的一部分，不需要插入
                if (s[i] == s[j])
                {
                    // 如果 i+1 < j，表示这两个字符之间还存在其他字符，可以直接依赖 dp[i + 1][j - 1]
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] : 0;
                }
                else
                {
                    // 如果 s[i] != s[j]，需要插入字符才能让字符串成为回文，选择插入字符后，插入到左边或右边所需要的最小插入次数
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        return dp[0][n - 1];                                // 最终结果存储在 dp[0][n-1]，即整个字符串成为回文串所需的最小插入次数
    }
};