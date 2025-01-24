//力扣：200. 岛屿数量
//https://leetcode.cn/problems/number-of-islands/description/


//方法：BFS
//时间复杂度：O(n*m)

//算法原理：
//遍历整个矩阵，每次找到「⼀块陆地」的时候：
//    • 说明找到「⼀个岛屿」，记录到最终结果 ret ⾥⾯；
//    • 并且将这个陆地相连的所有陆地，也就是这块「岛屿」，全部「变成海洋」。这样的话，我们下次遍历到这块岛屿的时候，它「已经是海洋」了，不会影响最终结果。
//    • 其中「变成海洋」的操作，可以利⽤「深搜」和「宽搜」解决，其实就是 733. 图像渲染 这道题~
//这样，当我们，遍历完全部的矩阵的时候， ret 存的就是最终结果。
class Solution 
{
public:
    // 定义一个方便表示二维坐标的类型，pii 是 pair<int, int> 的简写
    typedef pair<int, int> pii;

    // dx 和 dy 表示四个方向的移动（上下左右）
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    // vis 数组用于标记某个位置是否已经访问过
    bool vis[301][301];

    // n 和 m 分别表示网格的行数和列数
    int n, m;

    // 主函数，计算岛屿数量
    int numIslands(vector<vector<char>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        int ret = 0; // 用于存储岛屿的数量

        // 遍历整个网格
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == '1' && !vis[i][j])        // 如果当前位置是陆地 ('1') 且未被访问
                {
                    ret++;                                  // 发现一个新岛屿，计数 +1
                    bfs(grid, i, j);                        // 调用 BFS，将当前岛屿的所有连接部分标记为已访问
                }
            }
        }

        return ret;                                         // 返回总的岛屿数量
    }

    // BFS 函数，用于遍历某个岛屿的所有连接部分
    void bfs(vector<vector<char>>& grid, int i, int j) 
    {
        queue<pii> q;                                       // 使用队列来进行广度优先搜索
        q.push({ i, j });                                   // 将初始位置加入队列
        vis[i][j] = true;                                   // 标记初始位置为已访问

        while (q.size())                                   // 当队列不为空时，继续搜索
        { 
            auto [a, b] = q.front();                        // 获取队列的队首元素
            q.pop();                                        // 将队首元素移除

            // 遍历四个方向
            for (int k = 0; k < 4; k++) 
            {
                int x = a + dx[k];                          // 新位置的行
                int y = b + dy[k];                          // 新位置的列

                // 判断新位置是否在网格范围内、是否是陆地 ('1') 且未被访问
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !vis[x][y]) 
                {
                    q.push({ x, y });                       // 将新位置加入队列
                    vis[x][y] = true;                       // 标记新位置为已访问
                }
            }
        }
    }
};
