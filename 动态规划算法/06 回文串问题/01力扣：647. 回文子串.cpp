// 力扣：647. 回文子串
// 链接：https://leetcode.cn/problems/palindromic-substrings/description/

// 方法：动态规划
class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();                                       // 获取字符串的长度
        vector<vector<bool>> dp(n, vector<bool>(n, false));     // dp[i][j] 表示子串 s[i..j] 是否是回文子串
        int ret = 0;                                            // 用来记录回文子串的个数

        for (int i = n - 1; i >= 0; i--)                        // 从后往前遍历，i表示子串的起始位置
        {
            for (int j = i; j < n; j++)                         // 从i到n遍历，j表示子串的结束位置
            {
                if (s[i] == s[j])                               // 判断当前字符是否相等
                {
                    // 如果i和j指向的字符相等，且子串s[i+1..j-1]是回文（即i+1 < j时）或者i==j（一个字符本身是回文）
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] : true;
                }

                if (dp[i][j])
                {
                    ret++;                                      // 如果dp[i][j]为true，说明s[i..j]是回文子串，计数加1
                }
            }
        }

        return ret;                                             // 返回回文子串的总个数
    }
};