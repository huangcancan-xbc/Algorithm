// PTA：L1-034 点赞
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805098188750848&page=0

// 方法：哈希表
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int> hash;
	while (n--)
	{
		int n;
		cin >> n;

		int temp;
		while (n--)
		{
			cin >> temp;
			hash[temp]++;
		}
	}

	int key = 0, val = 0;
	for (const auto& p : hash)
	{
		// 如果当前标签的出现次数更多，或者次数相同但编号更大，则更新结果
		if (p.second > val || (p.second == val && p.first > key))
		{
			key = p.first;
			val = p.second;
		}
	}

	cout << key << " " << val << endl;

	return 0;
}