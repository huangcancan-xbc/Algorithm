// 力扣：72. 编辑距离
// 链接：https://leetcode.cn/problems/edit-distance/description/

// 方法：DP
// 思路：dp[i][j]：把 word1 的前 i 个字符变成 word2 的前 j 个字符，最少要几步。
// 如果当前字符一样：看前一个状态：dp[i-1][j-1]
// 如果不一样：有三种操作：
// 1. 删除word1的这个字符：dp[i-1][j]+1
// 2. 插入一个字符到word1：dp[i][j-1]+1
// 3. 替换word1的这个字符：dp[i-1][j-1]+1
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();

        // dp[i][j] 表示 word1 前 i 个字符转成 word2 前 j 个字符的代价
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        // 初始化边界：空串变非空串需要删除或插入，即任意一个串为空，操作次数直接就是另一个串的长度
        for (int i = 0; i <= n1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + 1;
                }
            }
        }

        return dp[n1][n2];
    }
};