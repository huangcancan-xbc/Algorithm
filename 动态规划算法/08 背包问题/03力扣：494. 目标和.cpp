// 力扣：494. 目标和
// 链接：https://leetcode.cn/problems/target-sum/description/

// 方法：动态规划（转换为子集和问题）
class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;                           // 计算数组总和 sum
        }

        int aim = (sum + target) / 2;           // 计算 aim，将问题转换为子集和问题：找到一个子集，使其和为 aim
        if (aim < 0 || (sum + target) % 2 == 1)
        {
            return 0;                           // 若 aim 为负数 或 (sum + target) 不是偶数，说明无法划分，返回 0
        }

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(aim + 1));    // 定义 DP 数组：dp[i][j] 表示前 i 个数中选取子集和为 j 的方案数
        dp[0][0] = 1;                           // 初始状态：选取 0 个数，使和为 0，只有 1 种方案（不选任何数）

        // 遍历数组，进行状态转移
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= aim; j++)
            {
                dp[i][j] = dp[i - 1][j];        // 不选当前元素 nums[i-1]，继承前 i-1 个数的方案数
                if (j >= nums[i - 1])           // 若当前子集和 j 足够容纳 nums[i-1]
                {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];     // 选择当前元素，累加方案数
                }
            }
        }

        return dp[n][aim];                      // 返回最终的方案数
    }
};


// 一维 DP 数组优化：
class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;
        }

        int aim = (sum + target) / 2;

        if (aim < 0 || (sum + target) % 2 == 1)
        {
            return 0;
        }

        int n = nums.size();
        vector<int> dp(aim + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = aim; j >= nums[i - 1]; j--)
            {
                dp[j] += dp[j - nums[i - 1]];

            }
        }

        return dp[aim];
    }
};