// 力扣：174. 地下城游戏
// 链接：https://leetcode.cn/problems/dungeon-game/description/

// 方法：动态规划
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();  // 获取地下城的行数和列数

        // 初始化dp数组，dp[i][j]表示从位置(i, j)到达终点所需的最小生命值
        // 注意我们在dp数组的右下角(n, m)处进行了边界初始化，dp[n][m-1] 和 dp[n-1][m] 为1，代表最终目标到达时需要至少1点生命值
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));         // 默认值为INT_MAX，表示不可能到达
        dp[n][m - 1] = dp[n - 1][m] = 1;                // 从右下角到目标点至少需要1点生命值

        // 从右下角开始遍历整个地下城
        for (int i = n - 1; i >= 0; i--)                // 从最后一行向上遍历
        {
            for (int j = m - 1; j >= 0; j--)            // 从最后一列向左遍历
            {
                // 选择右边和下边的最小值，表示我们从当前位置(i, j)可以选择
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]; // 向下走或向右走，所需的最小生命值
                dp[i][j] = max(1, dp[i][j]);            // 如果计算结果小于1，说明生命值不足以存活，因此要保证生命值至少为1
            }
        }

        return dp[0][0];                                // 最终返回从起始点(0, 0)出发所需的最小生命值
    }
};
