// PTA：L1-079 天梯赛的善良
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652358&page=0

// 方法：哈希表
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> nums(n);
	unordered_map<int, int> hash;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
		hash[nums[i]]++;
	}

	// 最小值及次数
	int minval = INT_MAX, mincount = INT_MAX;
	int maxval = 0, maxcount = 0;
	for (auto [a, b] : hash)
	{
		if (a < minval)
		{
			minval = a;
			mincount = b;
		}

		if (a > maxval)
		{
			maxval = a;
			maxcount = b;
		}
	}

	cout << minval << " " << mincount << endl;
	cout << maxval << " " << maxcount << endl;

	return 0;
}