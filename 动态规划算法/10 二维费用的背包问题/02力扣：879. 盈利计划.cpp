// 力扣：879. 盈利计划
// 链接：https://leetcode.cn/problems/profitable-schemes/description/

// 方法：动态规划（0-1 背包问题变形）
class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        int MOD = 1e9 + 7;                          // 取模值，防止结果溢出
        int len = group.size(), m = minProfit;      // 获取任务数量 len 和最低利润要求 m

        // 定义三维 DP 数组：dp[i][j][k] 表示考虑前 i 个任务，使用 j 名成员，且获得至少 k 的利润的方案数
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));

        for (int j = 0; j <= n; j++)
        {
            dp[0][j][0] = 1;                        // 初始化：当不选择任何任务时，利润为 0 仍然是一种有效方案
        }

        // 递推计算 dp 数组
        for (int i = 1; i <= len; i++)              // 遍历每个任务
        {
            for (int j = 0; j <= n; j++)            // 遍历可用成员数
            {
                for (int k = 0; k <= m; k++)        // 遍历利润目标
                {
                    dp[i][j][k] = dp[i - 1][j][k];  // 不选当前任务

                    if (j >= group[i - 1])          // 只有当当前任务需要的成员数不超过 j 时，才能选择该任务
                    {
                        // 选取当前任务时，利润应为 max(0, k - 当前任务利润)，k - profit[i - 1]为负本身有意义，数组下标从 0 开始，选则一个折中的方案
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];
                    }

                    dp[i][j][k] %= MOD;             // 取模防止溢出
                }
            }
        }

        return dp[len][n][m];                       // 返回在 n 个成员和至少 minProfit 利润下的方案数
    }
};



// 空间优化：
class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        int MOD = 1e9 + 7;
        int len = group.size(), m = minProfit;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= n; j++)
        {
            dp[j][0] = 1;
        }

        for (int i = 1; i <= len; i++)
        {
            for (int j = n; j >= group[i - 1]; j--)
            {
                for (int k = m; k >= 0; k--)
                {
                    dp[j][k] += dp[j - group[i - 1]][max(0, k - profit[i - 1])];

                    dp[j][k] %= MOD;
                }
            }
        }

        return dp[n][m];
    }
};