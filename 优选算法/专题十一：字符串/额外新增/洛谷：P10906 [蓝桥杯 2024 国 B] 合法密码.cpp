// 洛谷：P10906 [蓝桥杯 2024 国 B] 合法密码
// 链接：https://www.luogu.com.cn/problem/P10906

// 方法：字符串、模拟
#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
	int a=0, b=0;
	for (auto x : s)
	{
		if (x > '0' && x <= '9')
		{
			a = 1;				// 出现至少一次数字
		}
		if (x == '#')
		{
			b = 1;				// 出现至少一个符号字符
		}
		if (a + b == 2)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	string s = "kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
	int n = s.size();

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 8; j <= 16; j++)
		{
			if (check(s.substr(i, j)))
			{
				ret++;
			}
		}
	}

	cout << ret << endl;

	return 0;
}