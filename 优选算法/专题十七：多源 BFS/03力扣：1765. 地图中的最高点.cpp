//力扣：1765. 地图中的最高点
//链接：https://leetcode.cn/problems/map-of-highest-peak/description/


//方法：BFS
//算法原理：
//01矩阵的变型题，直接⽤多源 bfs 解决即可。
class Solution 
{
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));        // 注意初始化为-1，表示没有计算过
        queue<pair<int, int>> q;

        // 将所有0的位置加入队列，并将它们的距离设为0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({ i,j });
                    dist[i][j] = 0;
                }
            }
        }

        // 多源BFS，计算每个位置到最近0的距离
        while (q.size())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1)
                {
                    dist[x][y] = dist[a][b] + 1;                // 更新距离
                    q.push({ x,y });
                }
            }
        }

        return dist;
    }
};