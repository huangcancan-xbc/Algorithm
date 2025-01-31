//力扣：675. 为高尔夫比赛砍树
//链接：https://leetcode.cn/problems/cut-off-trees-for-golf-event/description/


//方法：BFS

//算法原理：
//a.先找出砍树的顺序；
//b.然后按照砍树的顺序，⼀个⼀个的⽤ bfs 求出最短路即可。
class Solution
{
public:
    int n, m;
    bool vis[51][51];
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int cutOffTree(vector<vector<int>>& forest)
    {
        n = forest.size(), m = forest[0].size();
        vector<pair<int, int>> v;               // 用 vector 来方便排序（其他也可）

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (forest[i][j] > 1)
                {
                    v.push_back({ i,j });       // 将所有的树存入 vector
                }
            }
        }

        // 排序
        sort(v.begin(), v.end(), [&](const pair<int, int>& n1, const pair<int, int>& n2)
            {
                return forest[n1.first][n1.second] < forest[n2.first][n2.second];
            });

        int begin1 = 0, end1 = 0;               // 起点
        int ret = 0;                            // 记录结果
        for (auto [a, b] : v)
        {
            int step = bfs(forest, begin1, end1, a, b); // 计算从 [begin1,end1] 到 [a,b] 的最短路
            if (step == -1)
            {
                return -1;                      // 只要有一个点不能到达，就返回 -1
            }
            ret += step;                        // 否则就累计上这最短的路
            begin1 = a, end1 = b;               // 别忘了更新起点
        }

        return ret;
    }

    int bfs(vector<vector<int>>& forest, int begin1, int end1, int begin2, int end2)
    {
        if (begin1 == begin2 && end1 == end2)
        {
            return 0;                           // 如果起点和终点相同，则直接返回 0
        }

        memset(vis, 0, sizeof(vis));            // 每次调用 BFS 都要重置 vis 数组（也可以将 vis 数组作为局部变量，但是要注意初始化全部为 false）
        queue<pair<int, int>> q;
        q.push({ begin1,end1 });
        vis[begin1][end1] = true;

        int count = 0;

        while (q.size())
        {
            int size = q.size();
            count++;

            while (size--)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && forest[x][y] && !vis[x][y])
                    {
                        if (x == begin2 && y == end2)
                        {
                            return count;       // 如果找到终点，则返回最短路
                        }

                        q.push({ x,y });
                        vis[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }
};


class Solution
{
public:
    int n, m;
    bool vis[51][51];
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    int cutOffTree(vector<vector<int>>& forest)
    {
        n = forest.size(), m = forest[0].size();
        vector<pair<int, int>> v;

        // 存储所有树的位置
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (forest[i][j] > 1)
                {
                    v.push_back({ i, j });
                }
            }
        }

        // 按照树的高度进行排序
        sort(v.begin(), v.end(), [&](const pair<int, int>& n1, const pair<int, int>& n2) 
            {
                return forest[n1.first][n1.second] < forest[n2.first][n2.second];
            });

        int begin1 = 0, end1 = 0;                   // 起点（0, 0）
        int ret = 0;

        // 按照树的高度顺序计算最短路径
        for (auto [a, b] : v)
        {
            int step = bfs(forest, begin1, end1, a, b);  // 从当前位置 (begin1, end1) 到目标位置 (a, b)
            if (step == -1)
            {
                return -1;                          // 如果无法到达某棵树，返回 -1
            }
            ret += step;
            begin1 = a, end1 = b;                   // 更新起点
        }

        return ret;
    }

    int bfs(vector<vector<int>>& forest, int begin1, int end1, int begin2, int end2)
    {
        if (begin1 == begin2 && end1 == end2)
        {
            return 0;                               // 如果起点和终点相同，直接返回 0
        }

        // 清空访问标记
        for (int i = 0; i < n; ++i)
        {
            fill(vis[i], vis[i] + m, false);
        }

        queue<pair<int, int>> q;
        q.push({ begin1, end1 });
        vis[begin1][end1] = true;

        int count = 0;

        while (!q.empty())
        {
            int size = q.size();
            count++;

            while (size--)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < n && y >= 0 && y < m && forest[x][y] && !vis[x][y])
                    {
                        if (x == begin2 && y == end2)
                        {
                            return count;           // 找到目标树，返回步数
                        }

                        q.push({ x, y });
                        vis[x][y] = true;
                    }
                }
            }
        }

        return -1;                                  // 如果无法到达目标位置，返回 -1
    }
};