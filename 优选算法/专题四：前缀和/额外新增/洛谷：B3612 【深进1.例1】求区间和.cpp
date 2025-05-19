// 洛谷：B3612 【深进1.例1】求区间和
// 链接：https://www.luogu.com.cn/problem/B3612

// 方法一：暴力（超时）
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int m = 0;
	cin >> m;
	while (m--)
	{
		int left = 0, right = 0;
		cin >> left >> right;

		long long ret = 0;
		for (int i = left; i <= right; i++)
		{
			ret += v[i];
		}

		cout << ret << endl;
	}

	return 0;
}



// 方法二：前缀和
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> v(n + 1),sum(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		sum[i] = sum[i - 1] + v[i];
	}

	int m = 0;
	cin >> m;
	while (m--)
	{
		int left = 0, right = 0;
		cin >> left >> right;

		cout << sum[right] - sum[left - 1] << endl;
	}

	return 0;
}