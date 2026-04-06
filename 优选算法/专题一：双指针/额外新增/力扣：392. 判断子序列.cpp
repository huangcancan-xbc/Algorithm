// 力扣：392. 判断子序列
// 链接：https://leetcode.cn/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：双指针
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        while (j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }

            j++;
        }

        return i == s.size();
    }
};





// 方法二：DP
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();

        // dp[i][j]表示s的前i个字符是不是t的前j个字符的子序列
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

        // 空串是任何串的子序列
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};