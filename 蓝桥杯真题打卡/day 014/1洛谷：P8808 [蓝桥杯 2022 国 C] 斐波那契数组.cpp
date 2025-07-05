//洛谷：P8808 [蓝桥杯 2022 国 C] 斐波那契数组
//链接：https://www.luogu.com.cn/problem/P8808


//方法一：递归

//只能过 70% 的测试用例，原因： Fibonacci 数列只能从1开始，不能从任意项开始(可尝试修改)
#include <iostream>
#include <vector>
using namespace std;

long long f[100000] = { 0 };
long long Fibonacci(long long n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return 1;
	}

	if (f[n] != 0)
	{
		return f[n];
	}
	f[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
	return f[n];
}

int main()
{
	int n = 0;
	cin >> n;
	int ret = 0;

	vector<long long> v(n + 1);
	for (long long i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (v[i] != Fibonacci(i))
		{
			ret++;
		}
	}

	cout << ret << endl;
	return 0;
}




//方法二：贪心/动态规划/数学/枚举

//思路：
//1. 暴力枚举数组的前两项，构造出斐波那契数列，并与输入数组进行比较，记录修改次数。
//2. 枚举斐波那契数列的前两项，构造出斐波那契数列，并与输入数组进行比较，记录修改次数。
//
//根据题目范围，只需要枚举到10^5即可。
//在最基础的斐波那契数列中，到了第 27 项就已是 10^5，已经超出了题目的范围，所以只能更改。
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

long long a[100010], b[100010];					// a 数组存储输入的原始数组，b 数组存储 Fibonacci 数列
int main()
{
	int n = 0;
	cin >> n;

	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int ret = INT_MAX;							// 记录最小的错误次数，初始化 “无穷大”

	for (int i = 1; i <= 100000; i++)
	{
		int count = 0, len = 0;
		b[1] = b[2] = i;						// 定义斐波那契数列的前两项为当前枚举值 i

		if (a[1] != b[1])						// 比较第一个元素，如果不等于 a[1]，需要一次修改
		{
			count++;
		}
		if (a[2] != b[2])						// 比较第二个元素，如果不等于 a[2]，需要一次修改
		{
			count++;
		}

		for (int j = 3; b[j-1] < 1e6; j++)		// 构造斐波那契数列，直到某项超过 10^6
		{
			b[j] = b[j - 1] + b[j - 2];
			if (b[j] != a[j])
			{
				count++;						// 不相等则累加修改次数
			}

			len = j;							// 记录生成的最大斐波那契数列的索引
		}

		count += (n - len);						// 对于序列中剩余的部分，直接累加修改次数
		ret = min(ret, count);					// 更新当前的最小修改次数
	}

	cout << ret << endl;
	return 0;
}