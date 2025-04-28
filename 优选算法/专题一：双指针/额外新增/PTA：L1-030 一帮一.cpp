// PTA：L1-030 一帮一
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805103557459968&page=0

// 方法：模拟、双指针、搜索
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<pair<int, string>> v;
	vector<bool> vis(n, false);

	for (int i = 0; i < n; i++)
	{
		int gender = 0;
		string name;
		cin >> gender >> name;

		v.push_back(make_pair(gender, name));
	}

	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (!vis[j] && v[i].first != v[j].first)
				{
					cout << v[i].second << " " << v[j].second << endl;
					vis[i] = true;
					vis[j] = true;
					break;
				}
			}
		}
	}

	return 0;
}