//洛谷：P8752 [蓝桥杯 2021 省 B2] 特殊年份
//链接：https://www.luogu.com.cn/problem/P8752


//方法：模拟
#include <iostream>
#include <string>
using namespace std;

bool is(string s)
{
	// 依次判断千位和十位是否相等，以及个位是否比百位
	if (s[0] == s[2] && ((s[3] - '0') - (s[1] - '0') == 1))
	{
		return true;
	}

	return false;
}
int main()
{
	int n = 5;
	int ret = 0;
	while (n--)
	{
		string s;
		cin >> s;

		if (is(s))
		{
			ret++;
		}
	}

	cout << ret << endl;

	return 0;
}