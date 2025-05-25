//力扣：994. 腐烂的橘子
//https://leetcode.cn/problems/rotting-oranges/description/


//方法：BFS
class Solution {
public:
    typedef pair<int, int> pii;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[40][40];
    int ret = 0;
    int n, m;

    int orangesRotting(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        queue<pii> q;
        bool news = false;

        // 扫描网格，将所有腐烂的橘子加入队列，初始时这些橘子开始腐烂
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == 2) 
                {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
                else if (grid[i][j] == 1) 
                {
                    news = true;                        // 发现新鲜橘子
                }
            }
        }

        if (!news)
        {
            return 0;                                   // 如果没有新鲜橘子，直接返回0
        }

        int minute = 0;                                 // 记录腐烂过程所需的分钟数

        // 进行BFS
        while (q.size()) 
        {
            int size = q.size();                        // 当前层级的橘子数
            bool cur = false;                           // 当前层级是否有新鲜橘子腐烂

            for (int i = 0; i < size; i++) 
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) 
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y]) 
                    {
                        q.push({ x, y });
                        vis[x][y] = true;               // 标记新鲜橘子为已腐烂
                        cur = true;                     // 当前轮次有新鲜橘子腐烂
                    }
                }
            }

            if (cur)                                    // 如果这一轮有橘子腐烂，时间加1
            {
                minute++;
            }
        }

        // 再次扫描一遍网格，看是否还有新鲜橘子
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] == 1 && !vis[i][j]) 
                {
                    return -1;                          // 仍然有新鲜橘子没有 腐烂
                }
            }
        }

        return minute;                                  // 返回腐烂过程所需的分钟数
    }
};





class Solution 
{
public:
    typedef pair<int, int> pii;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool vis[40][40];
    int n, m;

    int bfs(vector<vector<int>>& grid, queue<pii>& q)
    {
        int minutes = 0;                                // 记录腐烂过程所需的分钟数

        while (q.size())
        {
            int size = q.size();                        // 当前层级的橘子数
            bool rotThisRound = false;                  // 当前层级是否有新鲜橘子腐烂

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
                    {
                        q.push({ x, y });
                        vis[x][y] = true;               // 标记新鲜橘子为已腐烂
                        rotThisRound = true;            // 当前轮次有新鲜橘子腐烂
                    }
                }
            }

            if (rotThisRound)                           // 如果这一轮有橘子腐烂，时间加1
            {
                minutes++;
            }
        }

        return minutes;                                 // 返回腐烂过程所需的分钟数
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        queue<pii> q;
        bool foundFreshOrange = false;                  // 是否发现新鲜橘子

        // 扫描网格，将所有腐烂的橘子加入队列
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
                else if (grid[i][j] == 1)
                {
                    foundFreshOrange = true;            // 发现新鲜橘子
                }
            }
        }

        if (!foundFreshOrange)
        {
            return 0;                                   // 如果没有新鲜橘子，直接返回0
        }

        int minutes = bfs(grid, q);                     // 调用BFS函数

        // 再次扫描一遍网格，看是否还有新鲜橘子
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    return -1;                          // 仍然有新鲜橘子没有腐烂
                }
            }
        }

        return minutes;                                 // 返回腐烂过程所需的分钟数
    }
};