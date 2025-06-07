// PTA：L1-005 考试座位号
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805140211482624&page=0

// 方法：哈希表
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	unordered_map<int, pair<string,int>> map(n + 1);

	while (n--)
	{
		string s;
		int a = 0, b = 0;
		cin >> s >> a >> b;

		map[a] = { s,b };
	}

	int m = 0;
	cin >> m;
	vector<int> v(m, 0);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
		cout << map[v[i]].first << " " << map[v[i]].second << endl;
	}

	return 0;
}


// 方法：map
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, pair<string, int>> mp;				// 自动按 key（试机座位号）升序排序

	while (n--)
	{
		string id;
		int a, b;
		cin >> id >> a >> b;
		mp[a] = { id, b };
	}

	int m;
	cin >> m;
	while (m--)
	{
		int temp;
		cin >> temp;
		cout << mp[temp].first << " " << mp[temp].second << endl;
	}

	return 0;
}