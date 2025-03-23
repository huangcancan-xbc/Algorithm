// 力扣：188. 买卖股票的最佳时机 IV
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/

// 方法：动态规划（和123. 买卖股票的最佳时机 III 基本一致）
class Solution
{
public:
    const int INF = 0x3f3f3f3f;                 // 定义一个常量，表示无穷大，用于初始化值
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();

        k = min(k, n / 2);                      // 如果 k 比股票天数的一半还多，则将 k 限制为 n/2，因为最多进行的交易次数为 n/2 次

        // 创建一个二维数组 f，表示第 i 天的状态 j（0 表示持有，1 表示不持有），f[i][j] 的值表示第 i 天之后，最多 j 次交易能获得的最大利润
        vector<vector<int>> f(n, vector<int>(k + 1, -INF));     // 初始化为负无穷，表示不可能的情况

        auto g = f;                             // 创建一个二维数组 g，表示第 i 天之后的利润状态，g 数组用于记录最终的答案

        // 第 0 天的初始状态
        f[0][0] = -prices[0];                   // 第一天持有股票的最大利润是负的买入价格
        g[0][0] = 0;                            // 第一天不持有股票时，利润为 0

        for (int i = 1; i < n; i++)             // 从第二天开始，逐步更新动态规划表
        {
            for (int j = 0; j <= k; j++)        // 遍历交易次数（最多 k 次交易）
            {
                // 更新 f[i][j]，表示第 i 天持有股票的最大利润，比较不买股票与买股票的两种情况
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                
                g[i][j] = g[i - 1][j];          // g[i][j] 表示第 i 天不持有股票的最大利润，保持前一天不变

                // 如果 j - 1 >= 0，表示我们完成了 j - 1 次交易，尝试进行第 j 次交易
                if (j - 1 >= 0)
                {
                    // 更新 g[i][j]，表示第 i 天不持有股票时的最大利润，比较上一次完成 j - 1 次交易的利润加上今天卖出的收益
                    g[i][j] = max(g[i][j], f[i - 1][j - 1] + prices[i]);
                }
            }
        }

        int ret = 0;

        for (int i = 0; i <= k; i++)            // 遍历所有可能的交易状态，获取最终的最大利润
        {
            ret = max(ret, g[n - 1][i]);        // 取所有状态中的最大值
        }

        return ret;                             // 返回最终的最大利润
    }
};