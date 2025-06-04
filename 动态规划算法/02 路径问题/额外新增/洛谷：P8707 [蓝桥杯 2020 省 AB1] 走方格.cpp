// 洛谷：P8707 [蓝桥杯 2020 省 AB1] 走方格
// 链接：https://www.luogu.com.cn/problem/P8707

// 方法：动态规划
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i % 2 != 0 || j % 2 != 0)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}

	cout << dp[n][m] << endl;

	return 0;
}