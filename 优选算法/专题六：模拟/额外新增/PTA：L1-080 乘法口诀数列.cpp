// PTA：L1-080 乘法口诀数列
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652359&page=0

// 方法：模拟
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int a1 = 0, a2 = 0, n = 0;
	cin >> a1 >> a2 >> n;
	vector<int> v(n + 1);
	v[0] = a1;
	v[1] = a2;
	int index = 2;

	for (int i = 2; i < n; i++)
	{
		if (index > n - 1)
		{
			break;
		}

		int temp = v[i - 1] * v[i - 2];
		if (temp < 10)
		{
			v[index++] = temp;
		}
		else
		{
			string s = to_string(temp);
			for (int j = 0; j < s.size(); j++)
			{
				v[index++] = s[j] - '0';
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i];
		if (i != n - 1)
		{
			cout << " ";
		}
	}

	return 0;
}