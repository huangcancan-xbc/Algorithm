//洛谷：P1443 马的遍历
//链接：https://www.luogu.com.cn/problem/P1443


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>// memset
using namespace std;

int n, m, x, y;
vector<vector<int>> path;
typedef pair<int, int> pii;
int dx[8] = {2,1,-2,-1,2,1,-2,-1};
int dy[8] = {1,2,1,2,-1,-2,-1,-2};
int vis[420][420];

void bfs()
{
	queue<pii> q;
	q.push(pii(x, y));
	vis[x][y] = 0;					// 标记起点

	while (q.size())
	{
		auto [a, b] = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i], ny = b + dy[i];

			// 注意边界条件，只要 vis[nx][ny] == -1 就说明该点还没有被访问过
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == -1)
			{
				vis[nx][ny] = vis[a][b] + 1;		// 更新步数
				q.push(pii(nx, ny));				// 新点入队
			}
		}
	}

}

int main()
{
	cin >> n >> m >> x >> y;
	memset(vis, -1, sizeof(vis));			// 初始化步数数组为 -1，表示未到达

	bfs();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << vis[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}
//注意：
//vis[nx][ny] = vis[a][b] + 1;？？？
//
//1. vis[a][b]:表示从起点(x, y) 到当前点(a, b) 的最少步数。
//
//2. + 1 :每次从(a, b) 移动到(nx, ny)，马需要再走一步，因此步数增加 1。
//
//3. vis[nx][ny] 的更新 :
//	· 如果(nx, ny) 是第一次访问(vis[nx][ny] == -1)，更新为 vis[a][b] + 1。
//	· 这意味着找到了一条到达(nx, ny) 的路径，并记录了从起点到(nx, ny) 所需的步数。