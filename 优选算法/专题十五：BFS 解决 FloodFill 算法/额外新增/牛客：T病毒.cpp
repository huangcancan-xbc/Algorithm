//牛客：T病毒
//https://ac.nowcoder.com/acm/contest/97845/T
//参赛密码：517acm



#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool vis[40][40];
int n = 0, m = 0;

void dfs(vector<vector<char>>& v, int i, int j)
{
    queue<pii> q;
    q.push({ i,j });
    vis[i][j] = true;

    while (q.size())
    {
        auto [a, b] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int x = a + dx[k], y = b + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '*' && !vis[x][y])
            {
                q.push({ x,y });
                vis[x][y] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int ret = 0;

    vector<vector<char>> v(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '*' && !vis[i][j])
            {
                dfs(v, i, j);
                ret++;
            }
        }
    }

    if (ret)
    {
        cout << ret;
    }
    else
    {
        cout << "阳阳学长畅通无阻了";
    }
    return 0;
}