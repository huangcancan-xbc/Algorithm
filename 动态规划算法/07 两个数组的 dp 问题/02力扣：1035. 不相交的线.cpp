// 力扣：1035. 不相交的线
// 链接：https://leetcode.cn/problems/uncrossed-lines/description/

// 方法：动态规划
// 实际上，这是一个典型的最长公共子序列问题。代码、算法原理和上一题基本一致。
class Solution
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size(), m = nums2.size();                 // 获取两个数组的大小

        // 定义二维dp数组，其中dp[i][j]表示考虑nums1的前i个元素和nums2的前j个元素时，最多可以画出的不相交的线数
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // 填充dp数组
        for (int i = 1; i <= n; i++)                            // 遍历nums1数组
        {
            for (int j = 1; j <= m; j++)                        // 遍历nums2数组
            {
                // 如果当前元素相等，说明可以画一条线
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;            // 在前一个状态的基础上加上这一条新的不相交线
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 否则，选择不画线的情况，取前一行或者前一列的最大值
                }
            }
        }

        return dp[n][m];                                        // 返回最终的结果，即dp[n][m]表示在nums1和nums2全部元素中可以画出的最大不相交的线
    }
};