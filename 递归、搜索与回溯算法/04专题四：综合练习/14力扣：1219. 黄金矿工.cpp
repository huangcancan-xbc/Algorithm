// 力扣：1219. 黄金矿工
// 链接：https://leetcode.cn/problems/path-with-maximum-gold/

// 方法：DFS（深度优先搜索）+ 回溯法
// 算法原理：枚举矩阵中所有的位置当成起点，来⼀次深度优先遍历，统计出所有情况下能收集到的⻩⾦数的最⼤值即可。
// 1. 从每一个非零网格单元开始，通过 DFS 找到可能的路径，累计黄金数量。
// 2. 使用布尔数组 `vis` 记录访问状态，避免重复使用同一单元。
// 3. 在回溯过程中撤销状态，探索其他路径，保证尝试所有可能的路径。

class Solution
{
public:
    int ret = 0;                          // 最大黄金数量（结果变量）
    int dx[4] = { 0, 0, 1, -1 };          // 四个方向的横坐标变化（右、左、下、上）
    int dy[4] = { 1, -1, 0, 0 };          // 四个方向的纵坐标变化（右、左、下、上）
    bool vis[16][16] = { false };         // 访问标记数组，记录某个单元格是否已被访问
    int n, m;                             // 网格的行数 n 和列数 m

    void dfs(vector<vector<int>>& grid, int i, int j, int path)
    {
        ret = max(ret, path);             // 更新最大黄金数量

        for (int k = 0; k < 4; k++)       // 遍历四个方向
        {
            int x = i + dx[k];            // 计算下一个单元格的横坐标
            int y = j + dy[k];            // 计算下一个单元格的纵坐标

            // 检查下一个单元格是否在边界内、是否有黄金、是否未被访问
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0 && !vis[x][y])
            {
                vis[x][y] = true;         // 标记当前单元格为已访问

                // 递归搜索下一个单元格，并累计黄金数量
                dfs(grid, x, y, path + grid[x][y]);

                vis[x][y] = false;        // 回溯：撤销当前单元格的访问状态
            }
        }
    }

    int getMaximumGold(vector<vector<int>>& grid)
    {
        n = grid.size();                  // 获取网格行数
        m = grid[0].size();               // 获取网格列数

        for (int i = 0; i < n; i++)       // 遍历每一个网格单元作为起点
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)      // 如果当前单元格有黄金
                {
                    vis[i][j] = true;     // 标记当前单元格为已访问

                    // 从当前单元格开始搜索黄金路径
                    dfs(grid, i, j, grid[i][j]);

                    vis[i][j] = false;    // 回溯：撤销当前单元格的访问状态
                }
            }
        }

        return ret;                       // 返回找到的最大黄金数量
    }
};




//不将加和数 path 作为参数进行传递的写法：
class Solution
{
public:
    int ret = 0;                          // 最大黄金数量
    int sum = 0;                          // 当前黄金累计值
    int dx[4] = { 0, 0, 1, -1 };          // 四个方向的横坐标变化
    int dy[4] = { 1, -1, 0, 0 };          // 四个方向的纵坐标变化
    bool vis[16][16] = { false };         // 访问标记数组
    int n, m;                             // 网格行数和列数

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        ret = max(ret, sum);              // 更新最大黄金数量

        for (int k = 0; k < 4; k++)       // 遍历四个方向
        {
            int x = i + dx[k];            // 下一个单元格的横坐标
            int y = j + dy[k];            // 下一个单元格的纵坐标

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0 && !vis[x][y])
            {
                vis[x][y] = true;         // 标记为已访问
                sum += grid[x][y];        // 更新当前黄金累计值

                dfs(grid, x, y);          // 递归搜索

                sum -= grid[x][y];        // 回溯：撤销当前黄金累计值
                vis[x][y] = false;        // 回溯：撤销访问状态
            }
        }
    }

    int getMaximumGold(vector<vector<int>>& grid)
    {
        n = grid.size();                  // 获取网格行数
        m = grid[0].size();               // 获取网格列数

        for (int i = 0; i < n; i++)       // 遍历每一个网格单元作为起点
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)      // 如果当前单元格有黄金
                {
                    vis[i][j] = true;     // 标记为已访问
                    sum += grid[i][j];    // 更新当前黄金累计值

                    dfs(grid, i, j);      // 开始搜索

                    sum -= grid[i][j];    // 回溯：撤销当前黄金累计值
                    vis[i][j] = false;    // 回溯：撤销访问状态
                }
            }
        }

        return ret;                       // 返回找到的最大黄金数量
    }
};
