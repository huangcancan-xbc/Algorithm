// PTA：L1-020 帅到没朋友
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805117167976448&page=0

// 方法：模拟 + 哈希表
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	set<string> hash;
	vector<string> ret;

	while (n--)
	{
		int k = 0;
		cin >> k;
		vector<string> temp;
		for (int i = 0; i < k; i++)
		{
			string s;
			cin >> s;
			temp.push_back(s);
		}

		if (k > 1)
		{
			for (auto s : temp)
			{
				hash.insert(s);
			}
		}
	}

	int m = 0;
	cin >> m;

	vector<string> num;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		if (!hash.count(s))
		{
			ret.push_back(s);
			hash.insert(s);
		}
	}

	if (ret.size() == 0)
	{
		cout << "No one is handsome" << endl;
		return 0;
	}
	for (auto s : ret)
	{
		cout << s;
		if (s!= ret.back())
		{
			cout << " ";
		}
	}

	cout << endl;

	return 0;
}


// 部分优化：
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<string> hash;
	vector<string> ret;

	while (n--)
	{
		int k;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			string s;
			cin >> s;
			if (k > 1)  // 只有 k > 1 时才存入 hash
			{
				hash.insert(s);
			}
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;

		if (!hash.count(s))  // 没出现过才加入 ret
		{
			ret.push_back(s);
			hash.insert(s);  // 避免重复输出
		}
	}

	if (ret.empty())
	{
		cout << "No one is handsome" << endl;
	}
	else
	{
		for (size_t i = 0; i < ret.size(); i++)
		{
			if (i > 0)
			{
				cout << " ";  // 避免最后多余空格
			}

			cout << ret[i];
		}

		cout << endl;
	}

	return 0;
}