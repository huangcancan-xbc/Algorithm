//洛谷：B3625 迷宫寻路
//https://www.luogu.com.cn/problem/B3625

//方法一：BFS
#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int n, m;
bool vis[101][101];                         // bool数组标记是否访问过
typedef pair<int, int> pii;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool temp = false;                          // 标记是否找到路径

void bfs(vector<vector<char>>& s, int i, int j)
{
    queue<pii> q;
    q.push({ i,j });
    vis[i][j] = true;

    while (q.size())
    {
        auto [a, b] = q.front();
        q.pop();
        
        if (a == n - 1 && b == m - 1)       // 找到路径
        {
            temp = true;
            break;
        }

        for (int k = 0; k < 4; k++)
        {
            int x = a + dx[k], y = b + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.' && !vis[x][y])
            {
                vis[x][y] = true;
                q.push({ x,y });
            }
        }
    }

}
int main()
{
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }

    bfs(s, 0, 0);                               // 从(0,0)开始bfs

    if (temp)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}



//方法二：DFS
#include <iostream>
#include<vector>
using namespace std;

int n, m;
bool vis[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool temp = false;

void dfs(vector<vector<char>>& s, int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];               // 四个方向

        if (x == n - 1 && y == m - 1)                   // 如果找到路径
        {
            temp = true;                                // 标记找到路径
            return;
        }

        if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.' && !vis[x][y])
        {
            vis[x][y] = true;                           // 标记访问过
            dfs(s, x, y);                               // 递归搜索
        }
    }
}
int main()
{
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }

    dfs(s, 0, 0);

    if (temp)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}