// 力扣：740. 删除并获得点数
// 链接：https://leetcode.cn/problems/delete-and-earn/description/

// 方法：动态规划（类似“打家劫舍”问题）
class Solution
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        const int n = 10001;            // 题目限制数值范围 [1, 10000]
        int arr[n] = { 0 };             // 创建数组 arr，用于统计每个点数的总价值点数

        // 统计每个点数的总价值点数
        for (auto x : nums)
        {
            arr[x] += x;                // 累加所有相同的 x 值，相当于把问题转化为“打家劫舍”
        }

        vector<int> f(n, 0);            // f[i] 表示选择 i 时的最大收益
        vector<int> g(n, 0);            // g[i] 表示不选择 i 时的最大收益

        // 进行状态转移
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + arr[i];   // 若选择 i，则前一个数 i-1 不能选
            g[i] = max(g[i - 1], f[i - 1]);     // 若不选 i，则 i-1 可选也可不选，取最大值
        }

        return max(f[n - 1], g[n - 1]); // 取最终的最大收益
    }
};