// 力扣：1567. 乘积为正数的最长子数组长度
// 链接：https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/description/

// 方法：动态规划
class Solution
{
public:
    int getMaxLen(vector<int>& nums)
    {
        int n = nums.size();                    // 获取数组的长度
        vector<int> f(n + 1, 0), g(n + 1, 0);   // f[i] 表示以 i 结尾的乘积为正数的子数组的最长长度，g[i] 表示乘积为负数的最长子数组的长度
        int ret = 0;                            // 初始化结果为 0，表示最大子数组长度

        for (int i = 1; i <= n; i++)            // 遍历数组
        {
            if (nums[i - 1] > 0)                // 当前数字大于 0
            {
                f[i] = f[i - 1] + 1;            // 正数的子数组长度加 1
                g[i] = (g[i - 1] == 0) ? 0 : g[i - 1] + 1;      // 如果负数子数组长度不为 0，则负数子数组长度加 1，否则为 0
            }
            else if (nums[i - 1] < 0)           // 当前数字小于 0
            {
                f[i] = (g[i - 1] == 0) ? 0 : g[i - 1] + 1;      // 如果负数子数组长度不为 0，则转化为正数子数组
                g[i] = f[i - 1] + 1;            // 正数子数组长度加 1，负数子数组长度为负数
            }

            ret = max(ret, f[i]);               // 更新最大正数子数组长度，当nums[i-1] == 0时，f[i]和g[i]默认为0，无需处理
        }

        return ret;                             // 返回结果
    }
};