// 力扣：123. 买卖股票的最佳时机 III
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

// 方法：动态规划
class Solution
{
public:
    const int INF = 0x3f3f3f3f;                 // 0x3f3f3f3f 是一个16进制数，约等于 INT_MAX（即 0x7fffffff）的一半左右，这里使用 INF 表示无穷大，避免在计算中出现负溢出

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        // f[i][j] 表示在第 i 天结束时，进行 j 次交易（j 次买入和卖出）的最大利润，初始设为 -INF
        // g[i][j] 表示在第 i 天结束时，手上持有股票且进行了 j 次交易（j 次买入 j-1 次卖出）的最大利润
        vector<vector<int>> f(n, vector<int>(3, -INF));
        auto g = f;

        // 初始化第一天的情况
        f[0][0] = -prices[0];                   // 第一天买入股票，利润为 -prices[0]
        g[0][0] = 0;                            // 第一天未进行任何交易，利润为 0

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // 状态转移：不操作（观望）或在第 i 天买入股票（进行 j 次交易）
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);

                // 状态转移：保持之前的状态，即不卖出股票
                g[i][j] = g[i - 1][j];

                // 如果 j > 0，则可以考虑在第 i 天卖出股票（进行 j 次交易）
                if (j - 1 >= 0)
                {
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < 3; i++)
        {
            ret = max(ret, g[n - 1][i]);            // 计算最后一天结束时，不持有股票的最大利润
        }

        return ret;
    }
};