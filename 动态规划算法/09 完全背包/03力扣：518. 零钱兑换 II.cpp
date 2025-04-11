// 力扣：518. 零钱兑换 II
// 链接：https://leetcode.cn/problems/coin-change-ii/description/

// 方法：完全背包（动态规划）
class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        dp[0][0] = 1;                               // 不选任何硬币，凑出 0 元只有 1 种方法

        for (int i = 1; i <= n; ++i)                // 遍历硬币
        {
            for (int j = 0; j <= amount; ++j)       // 遍历金额
            {
                dp[i][j] = dp[i - 1][j];            // 不选第 i 个硬币
                if (j >= coins[i - 1])
                {
                    if (dp[i][j - coins[i - 1]] > INT_MAX - dp[i][j])
                    {
                        continue;                   // 确保在此处不会发生溢出，处理潜在的溢出情况
                    }
                    dp[i][j] += dp[i][j - coins[i - 1]];    // 选第 i 个硬币
                }
            }
        }

        return static_cast<int>(dp[n][amount]);     // 转换回 int 返回
        // return (int)dp[n][amount];
    }
};


// 一维 DP 数组的解法
class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);              // 一维DP数组，初始化为0
        dp[0] = 1;                                  // 凑出金额0有1种方法（不选任何硬币）

        
        for (int i = 1; i <= n; ++i)                // 遍历硬币
        {
            for (int j = coins[i - 1]; j <= amount; ++j)    // 遍历金额，从小到大遍历（完全背包问题）
            {
                if (dp[j - coins[i - 1]] <= INT_MAX - dp[j])
                {
                    dp[j] += dp[j - coins[i - 1]];  // 状态转移方程
                }
            }
        }

        return dp[amount];                          // 返回凑出amount的组合数
    }
};