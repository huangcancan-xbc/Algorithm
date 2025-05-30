// 洛谷：P8627 [蓝桥杯 2015 省 A] 饮料换购
// 链接：https://www.luogu.com.cn/problem/P8627

// 方法一：暴力循环模拟
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int ret = n, gai = n;
	while (gai > 2)
	{
		ret += gai / 3;
		gai = gai / 3 + gai % 3;
	}

	cout << ret << endl;

	return 0;
}



// 方法二：递归
#include <iostream>
using namespace std;

int is(int n)
{
	if (n < 3)
	{
		return 0;
	}

	int ret = n / 3;
	int gai = n % 3 + ret;

	return ret + is(gai);
}

int main()
{
	int n = 0;
	cin >> n;

	int ret = is(n) + n;
	cout << ret << endl;

	return 0;
}