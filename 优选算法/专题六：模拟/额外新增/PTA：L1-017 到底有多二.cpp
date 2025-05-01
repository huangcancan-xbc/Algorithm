// PTA：L1-017 到底有多二
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805121500692480&page=0

// 方法：模拟 + 字符串
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	double count = 0;

	for (auto x : s)
	{
		if (x == '2')
		{
			count++;
		}
	}

	double fu = 0, ou = 0;
	if (s[0] == '-')
	{
		fu = 0.5;
		n--;
	}
	if ((s[s.size() - 1] - '0') % 2 == 0)
	{
		ou = 1;
	}

	double ret = count / n * (1 + fu) * (1 + ou) * 100;

	printf("%.2f%%\n", ret);

	return 0;
}