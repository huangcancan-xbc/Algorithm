// 力扣：70. 爬楼梯
// 链接：https://leetcode.cn/problems/climbing-stairs/description/

// 方法：动态规划
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;                       // 如果楼梯只有 1 级、 2 级或 3 级，直接返回结果
        }

        // 动态规划数组 dp，dp[i] 表示到达第 i 级楼梯的不同方法数，长度为 n + 1，是因为要存储从第 0 级到第 n 级的所有状态
        // 例如：n = 5 时，dp[5] 表示到达第 5 级楼梯的方法数，因此数组大小需要到 5
        vector<int> dp(n + 1, 1);

        // 状态转移方程：dp[i] = dp[i - 1] + dp[i - 2]，含义：要到达第 i 级，可以从第 i-1 级迈一步，或者从第 i-2 级迈两步
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];                       // 返回到达第 n 级的方法总数
    }
};