//洛谷：P8780 [蓝桥杯 2022 省 B] 刷题统计
//链接：https://www.luogu.com.cn/problem/P8780


//方法一：暴力模拟
//时间复杂度O(n)
//部分会超时！
#include <iostream>
using namespace std;
int main()
{
	long long a = 0, b = 0, n = 0;
	cin >> a >> b >> n;

	long long target = 0;
	long long ret = 0;
	int day = 1;

	while (target < n)
	{	
		target += day < 6 ? a : b;
		ret++;

		//注意：当day为7时，需要变为1，这里直接取模+1，天数更新和 day=0 的情况就都解决了
		day = day % 7 + 1;
	}

	cout << ret << endl;

	return 0;
}



//方法二：正难则反
//时间复杂度O(1)
//思路：
//	1. 计算每周的刷题次数：a*5 + b*2
//	2. 计算总共需要刷的整周数：n/count
//	3. 计算要刷的整周数对应的天数：week*7
//	4. 计算整周数已经刷过的题目总数：week*count
//	5. 还剩最后一周，依次枚举每天的题目数量，直到题目总数大于等于n
#include <iostream>
using namespace std;
int main()
{
	long long a = 0, b = 0, n = 0;
	cin >> a >> b >> n;

	long long count = a * 5 + b * 2;		// 每周的刷题次数
	long long week = n / count;				// 总共需要刷的整周数
	long long ret = week * 7;				// 要刷的整周数对应的天数
	long long sum = week * count;			// 整周数已经刷过的题目总数

	// 还剩最后一周，依次枚举每天的题目数量，直到题目总数大于等于n
	while (sum < n)
	{
		ret++;
		if (ret % 7 <= 5 && ret % 7 > 0)	// 周一到周五
		{
			sum += a;
		}
		else 							    // 周六或周日
		{
			sum += b;
		}
	}

	cout << ret;
	return 0;
}