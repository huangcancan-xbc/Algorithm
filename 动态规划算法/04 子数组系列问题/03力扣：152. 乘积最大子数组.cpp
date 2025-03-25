// 力扣：152. 乘积最大子数组
// 链接：https://leetcode.cn/problems/maximum-product-subarray/description/

// 方法：动态规划（DP）
// 需要维护两个状态变量：
// 1. f[i] 表示以第 i 个元素结尾的最大乘积
// 2. g[i] 表示以第 i 个元素结尾的最小乘积
// 因为负数的乘积可能会变成正数，所以需要维护最小值。
class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> f(n + 1), g(n + 1);         // 初始化 f 和 g 数组，分别用于存储最大和最小乘积。
        f[0] = g[0] = 1;                        // 初始状态，空数组的最大和最小乘积为1

        int ret = INT_MIN;                      // 用来存储最终结果，初始化为最小整数

        // 遍历整个数组
        for (int i = 1; i <= n; i++)
        {
            // 分别存储当前元素、当前最大乘积乘以当前元素、当前最小乘积乘以当前元素
            int x = nums[i - 1], y = f[i - 1] * x, z = g[i - 1] * x;

            // 状态转移方程，更新 f[i] 和 g[i]，分别表示最大和最小乘积
            f[i] = max(x, max(y, z));           // 最大乘积取当前元素，或者前一个最大乘积/最小乘积与当前元素的乘积
            g[i] = min(x, min(y, z));           // 最小乘积同理

            ret = max(ret, f[i]);               // 更新结果，取最大乘积
        }

        return ret; // 返回最大乘积
    }
};