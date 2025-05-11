// PTA：L1-003 个位数统计
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805143738892288

// 方法：哈希表
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int hash[10] = { 0 };
	for (auto x : s)
	{
		hash[x - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (hash[i] > 0)
		{
			cout << i << ":" << hash[i] << endl;
		}
		
	}

	return 0;
}