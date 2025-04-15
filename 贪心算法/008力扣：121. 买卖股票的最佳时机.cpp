// 力扣：121. 买卖股票的最佳时机
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/

// 方法一：暴力法（超时）
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        int ret = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ret = max(ret, prices[i] - prices[j]);
            }
        }

        return ret;
    }
};



// 方法二：贪心
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        int ret = 0, min_prices = INT_MAX;              // 定义两个变量，min_prices 记录当前最小值，ret 记录最大利润
        for (int i = 0; i < n; i++)                     // 遍历数组，更新 min_prices 和 ret
        {
            if (prices[i] < min_prices)
            {
                min_prices = prices[i];                 // 如当前值小于 min_prices，则更新 min_prices
            }
            else
            {
                ret = max(ret, prices[i] - min_prices); // 否则，更新 ret
            }
        }

        return ret;                                     // 返回最大利润
    }
};
// 写法优化
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ret = 0, min_prices = INT_MAX;              // 定义两个变量，min_prices 记录当前最小值，ret 记录最大利润
        for (auto x : prices)                           // 遍历数组，更新 min_prices 和 ret
        {
            min_prices = min(x, min_prices);            // 当前值和 min_prices 作比较，找出最小值
            ret = max(ret, x - min_prices);             // 计算最大利润
        }

        return ret;
    }
};