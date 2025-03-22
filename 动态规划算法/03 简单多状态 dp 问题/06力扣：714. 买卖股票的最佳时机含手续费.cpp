// 力扣：714. 买卖股票的最佳时机含手续费
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// 方法：动态规划
class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();          // 获取股票价格数组的大小

        // 动态规划数组 f 和 g
        // f[i] 表示第 i 天买入（有股票）时的最大利润
        // g[i] 表示第 i 天卖出（可交易）时的最大利润
        vector<int> f(n, 0);            // 初始化 f 数组，表示持有股票时的利润，初始为 0
        auto g = f;                     // g 数组，用来表示可交易时的利润，初始为 f 数组的拷贝

        f[0] = -prices[0];              // 第 0 天买入股票，利润为负（即花费了价格）

        // 从第 1 天开始，进行状态转移
        for (int i = 1; i < n; i++)
        {
            // 第 i 天持有股票的最大利润，可以是：
            // 1. 保持之前的状态，即不变（f[i-1]）
            // 2. 在第 i 天买入股票，此时利润为前一天不持有股票的最大利润（g[i-1]）减去今天的股票价格
            f[i] = max(f[i - 1], g[i - 1] - prices[i]);

            // 第 i 天可以交易的最大利润，可以是：
            // 1. 保持之前的状态，即不变（g[i-1]）
            // 2. 在第 i 天卖出股票，此时利润为前一天持有股票的最大利润（f[i-1]）加上今天卖出的收益减去手续费
            g[i] = max(g[i - 1], f[i - 1] + prices[i] - fee);
        }

        // 返回最终的最大利润，可以是：
        // 1. 不持有股票且不是冷冻期的最大利润（g[n-1]）
        // 2. 持有股票的最大利润（f[n-1]）
        return max(g[n - 1], f[n - 1]); // 注意，直接返回 g[n-1] 也行，因为在最后一天持有股票并不会带来额外的收益，反而可能会由于需要支付买入成本而减少总利润。
    }
};