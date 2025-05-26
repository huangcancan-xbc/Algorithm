//牛客：我耳机呢？
//链接：https://ac.nowcoder.com/acm/contest/98971/G


//方法：BFS
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;

int BFS(vector<string>& v, pii start, char target)
{
    bool vis[15][15] = { false };

    queue<pii> q;
    q.push(start);
    vis[start.first][start.second] = true;

    int ret = 0;

    while (q.size())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            // 等价于 auto [a, b] = q.front();
            pii p = q.front();
            int a = p.first, b = p.second;

            q.pop();

            if (v[a][b] == target)
            {
                return ret;                         // 找到目标，返回距离
            }

            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k], y = b + dy[k];

                // 注意这里不能使用 v[x][y] == '.'（原因见后面详解）
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && v[x][y] != '#')
                {
                    vis[x][y] = true;
                    q.push({ x, y });
                }
            }
        }

        ret++;                                      // 每找一层，距离 + 1
    }

    return -1;
}
int main()
{
    cin >> n >> m;
    pii start1 = { -1, -1 };                        // 初始化start1为无效值

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '$')
            {
                start1 = { i,j };                   // 提前记录 $ 的位置，用于后面搜索的起点
            }
        }
    }

    int dist1 = BFS(v, { 0,0 }, '$');               // 从 (0,0) 到 $ 的最短路径
    if (dist1 == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    int dist2 = BFS(v, start1, 'e');                // 从 $ 到 e 的最短路径
    if (dist2 == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << dist1 + dist2;

    return 0;
}
//BFS 从起点出发，每当遇到一个合法的点（可以走的地方），就会把它加入队列进行进一步的搜索。
//然而，$ 和 e 都是特殊的目标字符。根据你的需求，在寻找目标字符时，我们不应该把目标字符视为不可走的障碍物。
//目标字符本身是可以访问的，它们应该被视为 "合法的"（即可以走到的）位置。
//因此，如果使用 v[x][y] == '.'，我们会排除掉目标字符 $ 或 e，使得 BFS 无法找到它们。这是错误的。



#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int bfs(const vector<string>& grid, int n, int m, pii start, char target) 
{
    queue<pii> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, -1));            // -1 表示未访问

    int sx = start.first, sy = start.second;
    q.push({ sx, sy });
    visited[sx][sy] = true;
    dist[sx][sy] = 0;                                           // 起点距离为 0

    while (!q.empty()) 
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) 
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') 
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });

                if (grid[nx][ny] == target) 
                {
                    return dist[nx][ny];                        // 找到目标，返回距离
                }
            }
        }
    }
    return -1;                                                  // 如果无法到达目标
}
int main() 
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    pii start, ear, canteen;

    // 读取地图，并记录起点、耳机和食堂的位置
    for (int i = 0; i < n; i++) 
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++) 
        {
            if (grid[i][j] == '$') ear = { i, j };
            if (grid[i][j] == 'e') canteen = { i, j };
        }
    }

    // 1. 从 (0, 0) 到耳机的最短路径
    int dist1 = bfs(grid, n, m, { 0, 0 }, '$');
    if (dist1 == -1) 
    {
        cout << -1 << endl;
        return 0;
    }

    // 2. 从耳机到食堂的最短路径
    int dist2 = bfs(grid, n, m, ear, 'e');
    if (dist2 == -1) 
    {
        cout << -1 << endl;
        return 0;
    }

    cout << dist1 + dist2 << endl;

    return 0;
}
//通过使用 v[x][y] != '#'，我们确保了 BFS 可以通过.和 $、e 等目标字符，而不被障碍物 # 阻挡。
//# 是障碍物，不允许进入，但目标字符 $ 和 e 是我们要找到的目标字符，应该允许走到这些位置，因此不应该把它们当作障碍物。