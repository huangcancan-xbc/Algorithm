// 力扣：132. 分割回文串 II
// 链接：https://leetcode.cn/problems/palindrome-partitioning-ii/description/

// 方法：动态规划
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();

        vector<vector<bool>> ispal(n, vector<bool>(n, false));  // ispal[i][j] 表示子字符串 s[i...j] 是否是回文串

        for (int i = n - 1; i >= 0; i--)                        // 从后往前遍历填充 ispal 数组
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])                               // 如果两个字符相等，且满足回文条件
                {
                    // 此时，当左右两个元素不是本身、不相邻就需要判断其内部是否也为回文串，其他情况均为回文串
                    ispal[i][j] = (i + 1 < j) ? ispal[i + 1][j - 1] : true;
                }
            }
        }

        vector<int> dp(n, INT_MAX);                             // dp[i] 表示将子串 s[0...i] 切割成回文子串的最小切割次数

        for (int i = 0; i < n; i++)
        {
            if (ispal[0][i])                                    // 如果 s[0...i] 是回文串，最小切割次数是 0
            {
                dp[i] = 0;
            }
            else                                                // 否则，遍历所有可能的分割点
            {
                for (int j = 1; j <= i; j++)
                {
                    if (ispal[j][i])
                    {
                        dp[i] = min(dp[i], dp[j - 1] + 1);      // 如果 s[j...i] 是回文串，更新 dp[i]
                    }
                }
            }
        }

        return dp[n - 1];                                       // dp[n-1] 就是整个字符串 s 的最小切割次数
    }
};