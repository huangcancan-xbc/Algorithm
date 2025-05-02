// PTA：L1-035 情人节
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805097018540032&page=0

// 方法：模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "", b = "";
	string s;

	int i = 1;
	while (cin >> s)
	{
		if (s == ".")
		{
			break;
		}

		if (i == 2)
		{
			a = s;
		}
		if (i == 14)
		{
			b = s;
		}

		i++;
	}

	if (i <= 2)
	{
		cout << "Momo... No one is for you ...";
	}
	else if (i > 2 && i <= 14)
	{
		cout << a << " is the only one for you...";
	}
	else
	{
		cout << a << " and " << b << " are inviting you to dinner...";
	}

	return 0;
}