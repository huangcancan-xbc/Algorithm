// 力扣：413. 等差数列划分
// 链接：https://leetcode.cn/problems/arithmetic-slices/description/

// 方法：动态规划
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();          // 获取数组的长度
        vector<int> dp(n, 0);         // dp[i] 表示以 i 为结尾的等差子数组的个数

        int sum = 0;                  // 用来累加等差子数组的总数
        for (int i = 2; i < n; i++)   // 从第三个元素开始判断
        {
            // 如果 nums[i] - nums[i-1] == nums[i-1] - nums[i-2]，说明当前元素和前两个元素构成了等差数列
            // 此时，dp[i] = dp[i-1] + 1，表示以 i 为结尾的等差子数组个数
            dp[i] = (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) ? dp[i - 1] + 1 : 0;

            sum += dp[i];             // 累加当前以 i 为结尾的等差子数组个数
        }

        return sum;                   // 返回所有等差子数组的总数
    }
};