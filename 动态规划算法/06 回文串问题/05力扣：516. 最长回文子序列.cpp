// 力扣：516. 最长回文子序列
// 链接：https://leetcode.cn/problems/longest-palindromic-subsequence/description/

// 方法：动态规划
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();                               // 获取字符串的长度
        
        vector<vector<int>> dp(n, vector<int>(n, 0));   // dp[i][j] 表示子字符串 s[i...j] 内的最长回文子序列的长度

        for (int i = n - 1; i >= 0; i--)                // 从字符串的末尾开始遍历，保证我们在填充 dp 数组时先处理小的区间
        {
            dp[i][i] = 1;                               // 这里表示 i 和 j 相等，单个字符本身是回文子序列，长度为 1
            
            for (int j = i + 1; j < n; j++)             // 对于每个 i，遍历 i 后面的子字符串
            {
                // 如果字符相等，考虑将这两个字符作为回文子序列的一部分
                if (s[i] == s[j])
                {
                    // 如果 i + 1 < j，表示两个字符之间还有其他字符，则取左边和右边的最长回文子序列的长度之和 + 2，如果 i + 1 = j，则只有两个字符，长度为 2
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] + 2 : 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // 如果左右边界字符不相等，就取左右边界内部相邻一个字符到另一边界的最长回文子序列的长度，取最大值
                }
            }
        }

        return dp[0][n - 1];                            // 最终，dp[0][n-1] 存储的是整个字符串 s 的最长回文子序列长度
    }
};