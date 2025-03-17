// 力扣：63. 不同路径 II
// 链接：https://leetcode.cn/problems/unique-paths-ii/description/

// 方法：动态规划
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));   // 创建 (m+1)x(n+1) 的 DP 数组，多出的第0行和第0列作为虚拟边界，初始化为0

        dp[0][1] = 1;                                           // 方式1：起点的虚拟右侧初始化为1个路径
        // dp[1][0] = 1;                                        // 方式2：起点的虚拟下侧初始化为1个路径

        // 状态转移：每个位置的路径数等于上方和左方的路径数之和
        for (int i = 1; i <= m; ++i)                            // 从 (1,1) 开始计算
        {
            for (int j = 1; j <= n; ++j)
            {
                // 如果当前位置没有障碍物（即为0），则计算路径数
                if (obstacleGrid[i - 1][j - 1] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];     // 上方 + 左方
                }
                // 如果当前位置有障碍物（即为1），路径数为0，已经由默认值0处理
            }
        }

        return dp[m][n];                                        // 返回右下角的路径数，即 dp[m][n]
    }
};
