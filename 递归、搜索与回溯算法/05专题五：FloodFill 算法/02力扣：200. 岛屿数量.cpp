// 力扣：200. 岛屿数量
// 链接：https://leetcode.cn/problems/number-of-islands/description/


// 方法：Floodfill算法

//算法原理：
//遍历整个矩阵，每次找到「⼀块陆地」的时候：
//• 说明找到「⼀个岛屿」，记录到最终结果 ret ⾥⾯；
//• 并且将这个陆地相连的所有陆地，也就是这块「岛屿」，全部「变成海洋」。这样的话，我们下次遍历到这块岛屿的时候，它「已经是海洋」了，不会影响最终结果。
//• 其中「变成海洋」的操作，可以利⽤「深搜」和「宽搜」解决，其实就是 733. 图像渲染 这道题~
//这样，当我们，遍历完全部的矩阵的时候， ret 存的就是最终结果。
//
//算法流程：
//1. 初始化 ret = 0 ，记录⽬前找到的岛屿数量;
//2. 双重循环遍历⼆维⽹格，每当遇到⼀块陆地，标记这是⼀个新的岛屿，然后将这块陆地相连的陆地全部变成海洋。
//递归函数的设计：
//1. 把当前格⼦标记为⽔；
//2. 向上、下、左、右四格递归寻找陆地，只有在下标位置合理的情况下，才会进⼊递归：
//    a.下⼀个位置的坐标合理；
//    b.并且下⼀个位置是陆地
class Solution
{
public:
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;
    bool vis[305][305];

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        vis[i][j] = true;                       // 将当前格⼦标记为⽔
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 下⼀个位置的坐标合理；并且下⼀个位置是陆地
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y])
            {
                dfs(grid, x, y);                // 递归寻找连通的陆地
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])    // 如果当前格⼦是陆地，并且没有被访问过
                {
                    ret++;                      // 记录⼀个新的岛屿
                    dfs(grid, i, j);            // 将这块陆地相连的陆地全部变成海洋
                }
            }
        }

        return ret;
    }
};


class Solution
{
public:
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y])
            {
                dfs(grid, x, y, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(305, vector<bool>(305));   // 优化：使用二维数组代替一维数组

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    dfs(grid, i, j, vis);                   // 将 vis 作为参数传递
                }
            }
        }

        return ret;
    }
};


class Solution
{
public:
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;
    vector<vector<bool>> vis;                               // 优化：使用二维数组代替一维数组, 并将 vis 作为全局变量

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y])
            {
                dfs(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }

        return ret;
    }
};



// 将岛屿计数在递归函数中更新，而不是在全局变量中更新
class Solution
{
public:
    int ret;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;
    vector<vector<bool>> vis;

    void dfs(vector<vector<char>>& grid, int i, int j, bool isNewIsland)
    {
        if (isNewIsland)
        {
            ret++;                           // 如果是新岛屿，增加计数
        }

        vis[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y])
            {
                dfs(grid, x, y, false);      // 后续递归不再更新岛屿计数
            }
        }
    }

    int numIslands(vector<vector<char>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, true);  // 新岛屿时传入 true
                }
            }
        }

        return ret;
    }
};
