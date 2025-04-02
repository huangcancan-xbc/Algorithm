// 力扣：1745. 分割回文串 IV
// 链接：https://leetcode.cn/problems/palindrome-partitioning-iv/description/

// 方法：动态规划
class Solution
{
public:
    bool checkPartitioning(string s)
    {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j]表示子字符串s[i...j]是否是回文串

        for (int i = n - 1; i >= 0; i--)                    // 填充dp表，首先处理所有的单字符和长度为2的子串
        {
            for (int j = i; j < n; j++)
            {
                
                if (s[i] == s[j])                           // 判断字符是否相等，并且满足回文条件
                {
                    
                    dp[i][j] = (i + 1 < j) ? dp[i + 1][j - 1] : true;   // 对于长度大于2的子串，检查中间部分是否是回文
                }
            }
        }

        // 使用dp表检查是否可以将字符串分为三个回文子串
        for (int i = 1; i < n - 1; i++)                     // i为第一个分割点，第二个分割点是j
        {
            for (int j = i; j < n - 1; j++)                 // j为第二个分割点
            {
                
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                {
                    return true;                            // 如果左部分、右部分和中间部分都是回文串，则返回true
                }
            }
        }

        return false;                                       // 如果没有找到合适的分割方式，返回false
    }
};