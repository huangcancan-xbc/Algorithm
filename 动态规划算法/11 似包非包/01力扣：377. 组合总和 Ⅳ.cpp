// 力扣：377. 组合总和 Ⅳ
// 链接：https://leetcode.cn/problems/combination-sum-iv/description/

// 方法：动态规划
class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<double> dp(target + 1, 0);           // 定义一维 DP 数组，dp[i] 表示凑成总和 i 的排列数
        dp[0] = 1;                                  // 递推边界，凑成总和 0 只有 1 种方式，即什么都不选

        // 计算所有可能的总和
        for (int i = 1; i <= target; i++)
        {
            for (auto x : nums)                     // 遍历可选的数字
            {
                if (i >= x)                         // 只有当前数字 x 不超过 i，才能使用它
                {
                    dp[i] += dp[i - x];             // 递推公式：dp[i] += dp[i - nums[j]]
                }
            }
        }

        return dp[target];                          // 返回凑成 target 的排列数
    }
};