// 力扣：5. 最长回文子串
// 链接：https://leetcode.cn/problems/longest-palindromic-substring/description/

// 方法：动态规划（Dynamic Programming）
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();                                   // 获取字符串的长度

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] 表示 s[i] 到 s[j] 是否是回文子串
        int len = 1, begin = 0;                             // 初始化最长回文子串的长度和起始位置

        // 动态规划，从下往上填充 dp 数组
        for (int i = n - 1; i >= 0; i--)                    // 从字符串的最后一个字符开始
        {
            for (int j = i; j < n; j++)                     // 对每个 i 开始，逐个判断 s[i] 到 s[j] 是否为回文
            {
                if (s[i] == s[j])                           // 如果 s[i] 等于 s[j]，可能是回文
                {
                    // 如果 i+1 到 j-1 的子串是回文，或者 i 和 j 相邻（i+1 > j-1），就是回文
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] : true;
                }

                if (dp[i][j] && j - i + 1 > len)            // 如果 dp[i][j] 为 true，且当前子串长度大于已记录的最大长度，则更新
                {
                    len = j - i + 1;                        // 更新回文子串的最大长度
                    begin = i;                              // 更新回文子串的起始位置
                }
            }
        }

        return s.substr(begin, len);                        // 返回最长回文子串，起始位置为 begin，长度为 len
    }
};