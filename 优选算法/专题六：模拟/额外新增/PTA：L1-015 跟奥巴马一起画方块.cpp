// PTA：L1-015 跟奥巴马一起画方块
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805124398956544&page=0

// 方法：模拟
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	char ch;
	cin >> n >> ch;

	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ch;
		}

		cout << endl;
	}

	return 0;
}