// 力扣：695. 岛屿的最大面积
// 链接：https://leetcode.cn/problems/max-area-of-island/description/


//方法：DFS 算法
//算法原理：
//• 遍历整个矩阵，每当遇到⼀块⼟地的时候，就⽤「深搜」或者「宽搜」将与这块⼟地相连的「整个岛屿」的⾯积计算出来。
//• 然后在搜索得到的「所有的岛屿⾯积」求⼀个「最⼤值」即可。
//• 在搜索过程中，为了「防⽌搜到重复的⼟地」：
//    ◦ 可以开⼀个同等规模的「布尔数组」，标记⼀下这个位置是否已经被访问过；
//    ◦ 也可以将原始矩阵的 1 修改成 0 ，但是这样操作会修改原始矩阵。

class Solution 
{
public:
    typedef pair<int, int> pii;                 // 定义坐标对，用于存储位置 (row, column)

    int dx[4] = { 0, 0, 1, -1 };                // 四个方向的行偏移量（右、左、下、上）
    int dy[4] = { 1, -1, 0, 0 };                // 四个方向的列偏移量（右、左、下、上）
    int row, column;                            // 记录网格的行数和列数

    // 广度优先搜索 (BFS) 用于计算某一岛屿的面积
    int bfs(vector<vector<int>>& grid, int i, int j) 
    {
        queue<pii> q;                           // 使用队列存储待处理的岛屿坐标
        q.push({ i, j });                       // 起点入队
        grid[i][j] = 0;                         // 标记该位置为已访问，避免重复访问
        int area = 1;                           // 记录当前岛屿的面积，初始为1

        while (q.size())                        // 当队列非空时
        {                 
            auto [a, b] = q.front();            // 当前坐标 (a, b)
            q.pop();                            // 弹出队头元素

            // 遍历四个方向
            for (int k = 0; k < 4; k++) 
            {
                int x = a + dx[k];              // 新行坐标
                int y = b + dy[k];              // 新列坐标

                // 判断新坐标是否有效且未访问
                if (x >= 0 && x < row && y >= 0 && y < column && grid[x][y] == 1) 
                {
                    q.push({ x, y });           // 将新坐标加入队列
                    grid[x][y] = 0;             // 标记为已访问
                    area++;                     // 岛屿面积加1
                }
            }
        }

        return area;                            // 返回计算的岛屿面积
    }

    // 主函数：计算网格中岛屿的最大面积
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        row = grid.size();                      // 获取网格的行数
        column = grid[0].size();                // 获取网格的列数
        int ret = 0;                            // 用于存储最大岛屿面积

        for (int i = 0; i < row; i++)           // 遍历每一行
        {      
            for (int j = 0; j < column; j++)    // 遍历每一列
            {  
                if (grid[i][j] == 1)            // 如果当前位置是岛屿
                {       
                    ret = max(ret, bfs(grid, i, j));  // 更新最大面积
                }
            }
        }

        return ret;                             // 返回最大岛屿面积
    }
};
