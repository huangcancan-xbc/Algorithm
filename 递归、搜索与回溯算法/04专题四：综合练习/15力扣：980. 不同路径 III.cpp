// 力扣：980. 不同路径 III
// 链接：https://leetcode.cn/problems/unique-paths-iii/

// 方法：DFS（深度优先搜索）+ 回溯法

//我们可以采用深度优先搜索（DFS），通过从起点出发递归地探索四个可能的移动方向（上下左右），
// 逐步访问每一个非障碍且未被访问过的格子。算法在遍历过程中记录已访问的路径，并确保每个空格子和终点都被恰好访问一次。
// 当递归到达终点时，检查是否所有需要访问的格子都已覆盖，如果满足条件则计入有效路径。
// 通过这种方式，算法能够系统性地枚举并统计所有满足题目要求的唯一路径数量。
class Solution
{
public:
    int ret = 0;                          // 最终的路径计数
    int dx[4] = { 0, 0, 1, -1 };          // 四个方向的横坐标变化（右、左、下、上）
    int dy[4] = { 1, -1, 0, 0 };          // 四个方向的纵坐标变化（右、左、下、上）
    bool vis[21][21] = { false };         // 访问标记数组，记录某个单元格是否已被访问
    int n, m, step = 0;                   // 网格行数 n、列数 m，以及需要访问的总单元格数 step

    void dfs(vector<vector<int>>& grid, int i, int j, int count)
    {
        // 如果到达终点
        if (grid[i][j] == 2)
        {
            if (count == step)            // 检查是否访问了所有空格
            {
                ret++;                    // 满足条件的路径数加一
            }
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            // 检查下一个单元格是否在边界内、不是障碍物、未被访问
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1 && !vis[x][y])
            {
                vis[x][y] = true;         // 标记当前单元格为已访问
                dfs(grid, x, y, count + 1); // 递归搜索下一个单元格
                vis[x][y] = false;        // 回溯：撤销当前单元格的访问状态
            }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int x1 = 0, y1 = 0;               // 起点的坐标

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)      // 统计需要经过的空单元格数量
                {
                    step++;
                }
                else if (grid[i][j] == 1) // 记录起点的坐标
                {
                    x1 = i;
                    y1 = j;
                }
            }
        }

        vis[x1][y1] = true;               // 标记起点为已访问
        step += 2;                        // 起点和终点也需要经过
        dfs(grid, x1, y1, 1);             // 从起点开始深度优先搜索

        return ret;                       // 返回满足条件的路径数
    }
};
