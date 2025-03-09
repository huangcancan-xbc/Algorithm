// 力扣：695. 岛屿的最大面积
// 链接：https://leetcode.cn/problems/max-area-of-island/description/
// （https://leetcode.cn/problems/ZL6zAn/description/）


//方法：Floodfill算法

//算法原理：
//• 遍历整个矩阵，每当遇到⼀块⼟地的时候，就⽤「深搜」或者「宽搜」将与这块⼟地相连的「整个岛屿」的⾯积计算出来。
//• 然后在搜索得到的「所有的岛屿⾯积」求⼀个「最⼤值」即可。
//• 在搜索过程中，为了「防⽌搜到重复的⼟地」：
//    ◦ 可以开⼀个同等规模的「布尔数组」，标记⼀下这个位置是否已经被访问过；
//    ◦ 也可以将原始矩阵的 1 修改成 0 ，但是这样操作会修改原始矩阵。
//
//算法流程：
//• 主函数内：
//    a.遍历整个数组，发现⼀块没有遍历到的⼟地之后，就⽤ dfs ，将与这块⼟地相连的岛屿的⾯积求出来；
//    b.然后将⾯积更新到最终结果 ret 中。
//• 深搜函数 dfs 中：
//    a.能够进到 dfs 函数中，说明是⼀个没遍历到的位置；
//    b.标记⼀下已经遍历过，设置⼀个变量 S = 1 （当前这个位置的⾯积为 1 ），记录最终的⾯积；
//    c.上下左右遍历四个位置：
//        ▪ 如果找到⼀块没有遍历到的⼟地，就将与这块⼟地相连的岛屿⾯积累加到 S 上；
//    d.循环结束后， S 中存的就是整块岛屿的⾯积，返回即可。


//全局变量：
class Solution
{
public:
    int ret;                            // 用于存储最大岛屿面积的结果
    int dx[4] = { 0, 0, 1, -1 };        // 定义四个方向的行偏移
    int dy[4] = { 1, -1, 0, 0 };        // 定义四个方向的列偏移
    bool vis[55][55];                   // 标记某个单元格是否已经访问
    int n, m;                           // n 为网格行数，m 为网格列数
    int count;                          // 记录当前岛屿的面积

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        count++;                        // 当前岛屿的面积加 1
        vis[i][j] = true;               // 标记当前单元格为已访问

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 检查新单元格是否在网格范围内、值为 1 且未被访问
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
            {
                dfs(grid, x, y);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])  // 如果当前单元格是岛屿（值为 1）且未被访问
                {
                    count = 0;          // 每一轮开始，初始化当前岛屿的面积为 0
                    dfs(grid, i, j);
                    ret = max(ret, count);          // 更新最大岛屿面积
                }
            }
        }

        return ret;
    }
};



//局部变量：
class Solution
{
public:
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[55][55];
    int n, m;

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int count = 1;                  // 初始化当前岛屿面积为 1（包含当前单元格）
        vis[i][j] = true;               // 标记当前单元格为已访问

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
            {
                count += dfs(grid, x, y);  // 累加相邻单元格的岛屿面积
            }
        }

        return count;                   // 返回当前岛屿的总面积
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // 如果当前单元格是岛屿（值为 1）且未被访问
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    ret = max(ret, dfs(grid, i, j));  // 更新最大岛屿面积
                }
            }
        }

        return ret;                     // 返回最大岛屿面积
    }
};