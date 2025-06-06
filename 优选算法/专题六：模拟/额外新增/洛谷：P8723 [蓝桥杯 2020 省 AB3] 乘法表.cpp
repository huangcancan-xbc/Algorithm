//洛谷：P8723 [蓝桥杯 2020 省 AB3] 乘法表
//链接：https://www.luogu.com.cn/problem/P8723
//如果你得了30分（警示后人）：
//乘法表里不仅结果要是P进制的，两个乘数也得是P进制的，所以，所有的输出都要用P进制的。


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string Base_conversion(int base, int num)
{
	string s;
	int temp = num;
	while(temp)
	{
		if (temp % base < 10)							// 注意：这里要判断一下是否小于10，因为如果是0-9，则不需要减10
		{
			s += temp % base + '0';
		}
		else
		{
			s += temp % base - 10 + 'A';				// 注意：这里要减10，因为10-15的字母是A-F
		}

		temp /= base;
	}
	reverse(s.begin(), s.end());						// 注意：这里要反转字符串，因为输出时是从右往左输出的

	return s;
}
int main()
{
	int p = 0;
	cin >> p;

	for (int i = 1; i < p; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			string begin = Base_conversion(p, i);		// p 进制表示第一个乘数
			string end = Base_conversion(p, j);			// p 进制表示第二个乘数
			string ret = Base_conversion(p, i * j);		// p 进制表示结果
			cout << begin << "*" << end << "=" << ret << " ";
		}
		cout << endl;
	}

	return 0;
}