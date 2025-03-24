// 力扣：53. 最大子数组和
// 链接：https://leetcode.cn/problems/maximum-subarray/description/

// 方法：动态规划
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n + 1, 0);               // 创建一个 dp 数组，dp[i] 表示以第 i 个元素结尾的最大子数组和

        int ret = INT_MIN;                      // 定义变量 ret 用来存储全局最大子数组和

        // 遍历数组中的每个元素，计算最大子数组和
        for (int i = 1; i <= n; i++)
        {
            // 动态规划方程：dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1])
            // 以第 i 个元素结尾的最大子数组和，等于当前元素 nums[i - 1] 与前一个元素结尾的最大子数组跟 dp[i - 1] 相加，取其中的最大值
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);

            ret = max(ret, dp[i]);              // 更新最大子数组和
        }

        return ret;                             // 返回结果，即全局最大子数组和
    }
};