//力扣：1926. 迷宫中离入口最近的出口
//链接：https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/


//方法：BFS

//算法原理：
//利⽤层序遍历来解决迷宫问题，是最经典的做法。
//我们可以从起点开始层序遍历，并且在遍历的过程中记录当前遍历的层数。这样就能在找到出⼝的时候，得到起点到出⼝的最短距离。
class Solution 
{
public:
    typedef pair<int, int> pii;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[105][105];

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int n = maze.size(), m = maze[0].size();
        queue<pii> q;
        q.push({ entrance[0],entrance[1] });
        vis[entrance[0]][entrance[1]] = true;

        int ret = 0;                                    // 记录当前层数
        while (q.size())
        {
            ret++;                                      // 累加当前层数
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.' && !vis[x][y])
                    {
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                        {
                            return ret;                 // 如果找到出口，则返回当前层数
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
    typedef pair<int, int> pii;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int n = maze.size(), m = maze[0].size();
        bool vis[m][n];                                 // 局部变量需要初始化，否则存储的是随机值(未定义行为)
        memset(vis, 0, sizeof vis);                     // 全部初始化为 0 （false）

        queue<pii> q;
        q.push({ entrance[0],entrance[1] });
        vis[entrance[0]][entrance[1]] = true;

        int ret = 0;
        while (q.size())
        {
            ret++;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = a + dx[k], y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.' && !vis[x][y])
                    {
                        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
                        {
                            return ret;
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