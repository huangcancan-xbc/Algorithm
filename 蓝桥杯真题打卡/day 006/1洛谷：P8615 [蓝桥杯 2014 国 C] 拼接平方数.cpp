//洛谷：P8615 [蓝桥杯 2014 国 C] 拼接平方数
//链接：https://www.luogu.com.cn/problem/P8615


//方法：取模分割法：
#include <iostream>
#include <cmath>
using namespace std;
bool ret[1000005];

bool is(int x)
{
	return (int)sqrt(x) == sqrt(x);			// 判断 x 是否是平方数
}

int main()
{
	int a = 0, b = 0;
	cin >> a >> b;

	for (int i = 1; i <= b; i++)			// 注意一定要从 1 开始，避免后面的 left 和 right 不在范围内（详解见结尾）
	{
		if (is(i))
		{
			ret[i] = 1;						// 如果 i 是平方数，则 ret[i] 置为 1
		}
	}

	for (int i = a; i <= b; i++)
	{
		if (ret[i])							// 如果 i 是平方数才进行下一步的判断
		{
			int k = 10;
			for (int j = 1; j <= 5; j++)	// 根据数据范围进行分割
			{
				int right = i % k;			// 拿到数字右边的 k 位数字
				int left = i / k;			// 拿到数字左边剩下的数字
				k *= 10;					// 改变 k 的值，继续分割
				if (left > 0 && right > 0 && ret[left] && ret[right])
				{
					cout << i << endl;		// 如果 left 和 right 都为平方数，则输出 i
					break;
				}
			}
		}
	}

	return 0;
}
// 注意：
// · 当数字 i 被分割时，例如 left = i / k 和 right = i % k，这些分割出来的数字可能小于 a 或大于 b。
// · 对于 ret 数组，只有[a, b] 范围内的值被初始化，范围之外的值是默认的 false，即使这些数字是平方数也无法被正确判断。
//因此，即使一个数字 i 本身符合条件，由于 left 或 right 的错误判断，会被错误排除。