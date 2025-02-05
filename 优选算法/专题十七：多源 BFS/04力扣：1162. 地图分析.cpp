//力扣：1162. 地图分析
//链接：https://leetcode.cn/problems/as-far-from-land-as-possible/description/


//方法：BFS + 正难则反
//算法原理：01矩阵的变型题，直接⽤多源 bfs 解决即可。
class Solution 
{
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)                // 将所有的 1 点加入队列（将所有的陆地视为“超级源点”），并将其距离设为 0
                {
                    dist[i][j] = 0;
                    q.push({ i,j });
                }
            }
        }

        int dx[4] = { 0,0,1,-1 };
        int dy[4] = { 1,-1,0,0 };
        int ret = -1;                               // 初始化为 -1 ，如果没有找到最远距离，则返回 -1

        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;
                    q.push({ x,y });
                    ret = max(ret, dist[x][y]);     // 更新最远距离
                }
            }
        }

        return ret;
    }
};