// 力扣：122. 买卖股票的最佳时机 II
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/

// 方法一：贪心 + 双指针
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size(), ret = 0;                     // 定义数组长度和最大利润

        for (int i = 0; i < n;)                             // 遍历数组
        {
            int j = i;                                      // 右指针的位置从当前位置开始
            while (j + 1 < n && prices[j + 1] > prices[j])
            {
                j++;                                        // 如有更高的价格，右指针就在合法区间内一直向右移动
            }

            ret += prices[j] - prices[i];                   // 累加单个区间的利润达到最大利润
            i = j + 1;                                      // 更新左指针到下一个价格不上升的位置
        }

        return ret;                                         // 返回最大利润
    }
};


// 方法二：贪心 + 拆分
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ret = 0;                                        // 定义最大利润
        for (int i = 1; i < prices.size(); i++)             // 遍历数组
        {
            int sum = prices[i] - prices[i - 1];            // 计算当前价格与前一价格的差值
            if (sum > 0)
            {
                ret += sum;                                 // 若差值大于0，则说明价格呈上升趋势，累加到最大利润中
            }
        }

        return ret;                                         // 返回最大利润
    }
};
// 不同写法：
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ret = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                ret += prices[i] - prices[i - 1];
            }
        }

        return ret;
    }
};