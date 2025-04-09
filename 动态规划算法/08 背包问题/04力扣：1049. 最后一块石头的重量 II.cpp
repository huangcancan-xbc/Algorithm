// 力扣：1049. 最后一块石头的重量 II
// 链接：https://leetcode.cn/problems/last-stone-weight-ii/description/

// 方法：01 背包（动态规划）
class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (auto x : stones)
        {
            sum += x;                           // 计算所有石头的总重量 sum
        }

        int n = stones.size(), m = sum / 2;     // 目标是找到一个子集，其和最接近 sum / 2

        vector<vector<int>> dp(n + 1, vector<int>(m + 1)); // 定义 dp 数组，dp[i][j] 表示前 i 块石头能否凑出重量 j 的最大重量

        // 遍历每一块石头
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];        // 不选当前石头，继承前 i-1 块石头的状态
                if (j >= stones[i - 1])         // 只有当前背包容量 j 能容纳 stones[i-1] 时，才考虑选它
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]); // 选当前石头，更新最大值
                }
            }
        }

        return sum - 2 * dp[n][m];              // 计算最终剩余的最小重量差
    }
};


// 一维 DP 数组优化：
class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        int sum = 0;
        for (auto x : stones)
        {
            sum += x;
        }

        int n = stones.size(), m = sum / 2;

        vector<int> dp(m + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= stones[i - 1]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }

        return sum - 2 * dp[m];
    }
};