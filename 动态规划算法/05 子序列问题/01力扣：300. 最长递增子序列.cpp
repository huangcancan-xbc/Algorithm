// 力扣：300. 最长递增子序列
// 链接：https://leetcode.cn/problems/longest-increasing-subsequence/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();                // 获取数组长度
        vector<int> dp(n, 1);               // dp[i] 表示以 nums[i] 结尾的最长递增子序列长度，初始化为 1

        int ret = 1;                        // 记录最终的最长子序列长度，初始化为 1
        for (int i = 0; i < n; i++)         // 遍历数组，计算每个位置的最长递增子序列
        {
            for (int j = 0; j < i; j++)     // 遍历 i 之前的元素，查找可以扩展的递增子序列
            {
                if (nums[j] < nums[i])      // 若 nums[j] 小于 nums[i]，说明可以连接成递增序列
                {
                    dp[i] = max(dp[j] + 1, dp[i]);  // 更新 dp[i]，取最大递增子序列长度
                }
            }

            ret = max(ret, dp[i]);          // 维护全局最长递增子序列长度
        }

        return ret;                         // 返回最长递增子序列长度
    }
};