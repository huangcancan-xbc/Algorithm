// PTA：L1-013 计算阶乘和
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805127389495296&page=0

// 方法：递推/模拟/记忆剪枝
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	if (n == 0 || n == 1 || n == 2)
	{
		cout << n << endl;
		return 0;
	}

	vector<int> v(n + 1, 0);
	v[1] = 1;
	v[2] = 2;

	long long ret = 0;
	ret += v[1] + v[2];
	for (int i = 3; i <= n; i++)
	{
		v[i] = i * v[i - 1];
		ret += v[i];
	}

	cout << ret << endl;

	return 0;
}