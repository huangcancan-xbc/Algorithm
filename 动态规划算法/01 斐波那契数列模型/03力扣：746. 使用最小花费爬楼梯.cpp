// 力扣：746. 使用最小花费爬楼梯
// 链接：https://leetcode.cn/problems/min-cost-climbing-stairs/description/

// 方法：动态规划（Dynamic Programming, DP）

// 解法一：以 i 位置为结尾，从左往右
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);              // dp[i] 表示到达第 i 级台阶的最小花费

        for (int i = 2; i <= n; i++)        // 从第 2 级台阶开始计算
        {
            // 到达第 i 级台阶有两种方式：
            // 1. 从 i-1 级台阶走一步过来，花费 dp[i - 1] + cost[i - 1]
            // 2. 从 i-2 级台阶走两步过来，花费 dp[i - 2] + cost[i - 2]
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];                       // 结果是到达 n 级台阶的最小花费
    }
};

// 优化：滚动数组（减少空间复杂度）
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        int prev1 = 0, prev2 = 0;           // 用两个变量代替 dp 数组，prev1 代表 dp[i-2]，prev2 代表 dp[i-1]

        for (int i = 2; i <= n; i++)        // 从第 2 级台阶开始计算
        {
            // 计算当前最小花费
            int cur = min(prev2 + cost[i - 1], prev1 + cost[i - 2]);
            prev1 = prev2;                  // 更新 prev1 为上一轮的 prev2
            prev2 = cur;                    // 更新 prev2 为当前计算的 cur
        }

        return prev2;                       // 最终的最小花费
    }
};


// 解法二：以 i 位置为起点，从右往左
class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n);                  // dp[i] 表示从第 i 级台阶出发所需的最小花费
        dp[n - 1] = cost[n - 1];            // 最后一阶的花费就是本身
        dp[n - 2] = cost[n - 2];            // 倒数第二阶的花费也是本身

        for (int i = n - 3; i >= 0; i--)    // 从倒数第三级台阶开始计算
        {
            // 到达终点有两种方式：
            // 1. 走一步到 dp[i+1]，再加上 cost[i]
            // 2. 走两步到 dp[i+2]，再加上 cost[i]
            dp[i] = min(cost[i] + dp[i + 1], cost[i] + dp[i + 2]);
            // dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);  // 等价写法
        }

        return min(dp[0], dp[1]);           // 结果是从第 0 或第 1 级台阶出发的最小花费
    }
};