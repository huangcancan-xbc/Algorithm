// 力扣：376. 摆动序列
// 链接：https://leetcode.cn/problems/wiggle-subsequence/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int n = nums.size();                    // 获取数组的长度

        // 初始化 f 和 g 数组，每个位置的初始值都为 1，因为每个元素本身可以是一个摆动序列的最小长度
        // f[i] 表示以 nums[i] 为上升点的最长摆动序列长度，g[i] 表示以 nums[i] 为下降点的最长摆动序列长度
        vector<int> f(n, 1), g(n, 1);
        
        int ret = 1;                            // 记录最长摆动序列的长度，初始值为 1

        for (int i = 1; i < n; i++)             // 遍历数组，从第二个元素开始
        {
            for (int j = 0; j < i; j++)         // 遍历 i 之前的所有元素，找到能够和 nums[i] 形成摆动序列的元素
            {
                if (nums[j] < nums[i])          // nums[i] 作为上升点（即 nums[j] < nums[i]），更新 f[i]
                {
                    f[i] = max(g[j] + 1, f[i]); // 选择最优解，g[j] 表示 nums[j] 是下降点的最大序列长度
                }
                else if (nums[j] > nums[i])     // nums[i] 作为下降点（即 nums[j] > nums[i]），更新 g[i]
                {
                    g[i] = max(f[j] + 1, g[i]); // 选择最优解，f[j] 表示 nums[j] 是上升点的最大序列长度
                }
            }

            ret = max(ret, max(f[i], g[i]));    // 更新全局最优解，取 f[i] 和 g[i] 的最大值
        }

        return ret;                             // 返回最长摆动子序列的长度
    }
};