//力扣：542. 01 矩阵
//链接：https://leetcode.cn/problems/01-matrix/description/


// 方法一：单源最短路径（BFS）
// 最坏时间复杂度接近O(nm^3)，所以会超时！

//• 第⼀种⽅式：从每⼀个 1 开始，然后通过层序遍历找到离它最近的 0 。这⼀种⽅式，我们会以所有的 1 起点，来⼀次层序遍历，
// 势必会遍历到很多重复的点。并且如果矩阵中只有⼀个 0 的话，每⼀次层序遍历都要遍历很多层，时间复杂度较⾼。
class Solution
{
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));

        // 遍历矩阵，每次遇到非零元素，进行BFS计算距离
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] != 0)
                {
                    dist[i][j] = bfs(mat, i, j);                // 非零元素需要计算与最近0的距离
                }
            }
        }

        return dist;
    }

    // 使用BFS求解(i, j)到最近0的最短路径
    int bfs(vector<vector<int>>& mat, int i, int j)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, false));    // 记录是否访问过
        queue<pair<int, int>> q;
        q.push({ i,j });
        vis[i][j] = true;
        int step = 0;                                           // 记录步数（即距离）

        while (q.size())
        {
            int size = q.size();
            step++;

            while (size--)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
                    {
                        if (mat[x][y] == 0)
                        {
                            return step;                        // 找到0，返回当前步数
                        }

                        q.push({ x,y });                        // 否则继续向队列中加入邻居节点
                        vis[x][y] = true;
                    }
                }
            }
        }

        return -1;                                              // 如果没有找到0，返回-1（理论上不会到达这里）
    }
};



// 方法二：多源最短路径（BFS/Dijkstra）
// 使用多源BFS，从所有的0出发，向四周扩展，计算每个位置到最近0的距离。

//算法原理：
//• 换⼀种⽅式：从 0 开始层序遍历，并且记录遍历的层数。当第⼀次碰到 1 的时候，当前的层数就是这个 1 离 0 的最短距离。
//这⼀种⽅式，我们在遍历的时候标记⼀下处理过的 1 ，能够做到只⽤遍历整个矩阵⼀次，就能得到最终结果。
//
//但是，这⾥有⼀个问题， 0 是有很多个的，我们怎么才能保证遇到的 1 距离这⼀个 0 是最近的呢？
//其实很简单，我们可以先把所有的 0 都放在队列中，把它们当成⼀个整体，每次把当前队列⾥⾯的所有元素向外扩展⼀次。
class Solution
{
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));        // 注意初始化为-1，表示没有计算过
        queue<pair<int, int>> q;

        // 将所有0的位置加入队列，并将它们的距离设为0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
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