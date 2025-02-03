//力扣：1020. 飞地的数量
//链接：https://leetcode.cn/problems/number-of-enclaves/description/


//方法：BFS + 正难则反

//算法原理：
//正难则反：从边上的 1 开始搜索，把与边上 1 相连的联通区域全部标记⼀下；
//然后再遍历⼀遍矩阵，看看哪些位置的 1 没有被标记即可标记的时候，可以⽤「多源 bfs 」解决。
class Solution
{
public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));

        // 遍历一遍矩阵，把边界上的 1 加入队列，并标记已访问
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({ i,j });
                        vis[i][j] = true;
                    }
                }
            }
        }

        // BFS
        int dx[4] = { 0,0,1,-1 };
        int dy[4] = { 1,-1,0,0 };
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !vis[x][y])
                {
                    q.push({ x,y });
                    vis[x][y] = true;
                }
            }
        }

        // 遍历一遍矩阵，看看哪些位置的 1 没有被标记，累加结果
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    ret++;
                }
            }
        }

        return ret;
    }
};