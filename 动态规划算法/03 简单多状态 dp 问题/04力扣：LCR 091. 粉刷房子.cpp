// 力扣：LCR 091. 粉刷房子
// 链接：https://leetcode.cn/problems/JEj789/description/

// 方法：动态规划
class Solution
{
public:
    int minCost(vector<vector<int>>& costs)
    {
        int n = costs.size();       // 房子的数量

        // dp[i][j] 表示第 i 个房子使用颜色 j 时的最小费用，j 取值 0, 1, 2 分别代表颜色 0, 1, 2
        vector<vector<int>> dp(n + 1, vector<int>(3));

        // 从第 1 个房子开始，到第 n 个房子进行计算
        for (int i = 1; i < n + 1; i++)
        {
            // 计算第 i 个房子粉刷颜色 0 的最小成本，要求与上一房子颜色 1 或 2 不同
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            // 计算第 i 个房子粉刷颜色 1 的最小成本，要求与上一房子颜色 0 或 2 不同
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            // 计算第 i 个房子粉刷颜色 2 的最小成本，要求与上一房子颜色 0 或 1 不同
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }

        // 返回最后一个房子使用任意颜色的最小费用
        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};