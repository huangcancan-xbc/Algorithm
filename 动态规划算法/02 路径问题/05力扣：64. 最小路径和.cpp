// 力扣：64. 最小路径和
// 链接：https://leetcode.cn/problems/minimum-path-sum/description/

// 方法：动态规划
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();    // 获取网格的行数n和列数m

        // dp[i][j] 表示从(0,0)到(i-1,j-1)的最小路径和，创建一个大小为(n+1)*(m+1)的dp数组，初始化为INT_MAX（表示无效值）
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

        dp[0][1] = dp[1][0] = 0;                    // 设置起点(0,0)的值为0，因为从起点到起点路径和为0

        // 遍历整个网格
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 当前点的最小路径和是从上方或左方两者中最小的路径和加上当前点的值
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[n][m];                            // 返回右下角的最小路径和，即到达(grid[n-1][m-1])的最小路径和
    }
};
