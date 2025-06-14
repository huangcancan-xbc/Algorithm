// 洛谷：P8748 [蓝桥杯 2021 省 B] 时间显示
// 链接：https://www.luogu.com.cn/problem/P8748

// 方法：数学模拟
#include <iostream>
using namespace std;

int main()
{
	long long s = 0;
	cin >> s;

	long long n = s / 1000 % 86400;
	long long shi = n / 3600;
	long long fen = (n % 3600) / 60;
	long long miao = n % 60;

	printf("%02d:%02d:%02d\n", shi, fen, miao);

	return 0;
}