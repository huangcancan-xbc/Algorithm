// PTA：L1-006 连续因子
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805138600869888&page=0

// 方法：模拟 + 数学
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n = 0;
	cin >> n;

	int maxLen = 0, star = 0;					// 最大连续因子的长度和起始位置
	for (int i = 2; i <= sqrt(n); i++)
	{
		long long temp = 1;
		for (int j = i; temp * j <= n; j++)		// 从当前位置开始尝试连续因子
		{
			temp *= j;
			if (n % temp == 0)					// 如果找到了能整除的因子（合法因子），则更新最大连续因子
			{
				if (j - i + 1 > maxLen)
				{
					maxLen = j - i + 1;			// 更新最大连续因子的长度
					star = i;					// 更新最大连续因子的起始位置
				}
			}
		}
	}

	if (maxLen == 0)
	{
		maxLen = 1;								// 如果 maxLen 还是0，说明n本身是一个质数，没有合法因子
		star = n;								// 返回起始位置为 n 本身
	}
	
	cout << maxLen << endl;
	for (int i = star; maxLen > 0; i++)
	{
		cout << i;
		maxLen--;
		if (maxLen > 0)
		{
			cout << "*";
		}
	}

	cout << endl;

	return 0;
}


// 优化版：
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	int maxLen = 0, start = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i != 0)
		{
			continue;							// 跳过非因子
		}

		long long temp = 1;
		for (int j = i; ; j++)
		{
			temp *= j;
			if (temp > n || n % temp != 0)
			{
				break;							// 提前终止
			}

			if (j - i + 1 > maxLen)
			{
				maxLen = j - i + 1;
				start = i;
			}
		}
	}

	if (maxLen == 0)
	{
		cout << 1 << endl << n << endl;
		return 0;
	}

	cout << maxLen << endl;
	for (int i = start; i < start + maxLen; i++)
	{
		cout << i;
		if (i < start + maxLen - 1)
		{
			cout << "*";
		}
	}

	cout << endl;

	return 0;
}