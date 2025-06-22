// 洛谷：P10898 [蓝桥杯 2024 省 C] 拼正方形
// 链接：https://www.luogu.com.cn/problem/P10898

// 方法：数学
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n = (7385137888721 + 10470245 / 4) * 4;
	long long ret = (long long)sqrtl(n);

	cout << ret << endl;

	return 0;
}