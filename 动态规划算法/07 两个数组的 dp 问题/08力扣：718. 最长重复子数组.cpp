// 力扣：718. 最长重复子数组
// 链接：https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/

// 方法：动态规划
class Solution
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();

        // dp[i][j] 表示 nums1[0...i] 和 nums2[0...j] 结尾的最长公共子数组长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ret = 0;                                // 记录最长公共子数组长度
        // 遍历 nums1 和 nums2
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])   // 若当前元素相等，则状态转移
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ret = max(ret, dp[i][j]);       // 更新最长长度
                }
            }
        }

        return ret;
    }
};