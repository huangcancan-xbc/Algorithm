// 力扣：309. 买卖股票的最佳时机含冷冻期
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

// 方法：动态规划
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();                      // 获取价格数组的大小

        // 动态规划数组 dp，dp[i][j] 表示第 i 天状态为 j 时的最大利润
        // j = 0 表示买入，j = 1 表示可交易，j = 2 表示冷冻期
        vector<vector<int>> dp(n, vector<int>(3));

        dp[0][0] = -prices[0];                      // 初始化第 0 天的状态，第 0 天买入股票，利润为负（买入的花费）

        // 从第 1 天开始，进行状态转移
        for (int i = 1; i < n; i++)
        {
            // 状态转移方程：
            // dp[i][0]：第 i 天持有股票的最大利润，等于之前持有股票的最大利润（dp[i - 1][0]）或者之前没有持有股票且卖出股票的最大利润（dp[i - 1][1] - prices[i]）
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);

            // dp[i][1]：第 i 天处于可交易状态的最大利润，等于之前持有股票的最大利润（dp[i - 1][1])或者之前处于冷冻期的最大利润（dp[i - 1][2])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);

            // dp[i][2]：第 i 天处于冷冻期的最大利润，等于之前持有股票的最大利润和卖出股票的最大利润之和（dp[i - 1][0] + prices[i])
            dp[i][2] = dp[i - 1][0] + prices[i];
        }

        return max(dp[n - 1][1], dp[n - 1][2]);     // 返回最后一天处于可交易状态或冷冻期的最大利润
    }
};