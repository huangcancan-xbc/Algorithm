// 力扣：322. 零钱兑换
// 链接：https://leetcode.cn/problems/coin-change/description/

// 方法：完全背包（动态规划）
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        const int INF = 0x3f3f3f3f;             // 定义一个较大的数，表示无法凑出的情况

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));     // 定义 dp 数组，dp[i][j] 表示前 i 种硬币凑出金额 j 所需的最少硬币数

        for (int i = 1; i <= amount; i++)
        {
            dp[0][i] = INF;                     // 初始化：若金额 j > 0 且无硬币可选，则无法凑出，设为 INF
        }

        // 遍历所有硬币
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];        // 不选当前硬币，继承前 i-1 种硬币的最优解
                if (j >= coins[i - 1])          // 当前金额 j 足够容纳 coins[i-1]，则考虑选取
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);  // 选当前硬币，更新最小硬币数
                }
            }
        }

        return dp[n][amount] >= INF ? -1 : dp[n][amount];           // 若 dp[n][amount] 仍为 INF，说明无法凑出，返回 -1，否则返回最少硬币数
    }
};


// 一维 DP 数组优化：
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        const int INF = 0x3f3f3f3f;

        vector<int> dp(amount + 1);
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = INF;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);

            }
        }

        return dp[amount] >= INF ? -1 : dp[amount];
    }
};