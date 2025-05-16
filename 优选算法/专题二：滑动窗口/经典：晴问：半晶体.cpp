//晴问：半晶体
//链接：https://sunnywhy.com/contest/145/problem/B


//方法：滑动窗口
//
//题目难懂，简单解读：
//我们需要找出一个区间[a, b]，其中 a 和 b 分别是晶体的最小和最大值，并且这个区间包含至少一半的晶体。
//这里的“一半”是向上取整的，即包含 ⌈n / 2⌉ 个晶体（如果 n 是奇数，就是(n + 1) / 2）。
//能量场的大小定义为 b - a，我们需要找出最小的 b - a，使得该区间包含至少一半的晶体。
//
//算法原理：
//1. 排序：首先对所有晶体的大小进行排序。这样，任何区间内的最小值和最大值都会是区间的两个端点。
//2. 滑动窗口：我们利用滑动窗口的方式来遍历所有可能的子数组。每次窗口内的元素数量满足至少
//包含 ⌈n / 2⌉ 个元素时，我们就计算窗口的大小，即区间的最大值和最小值之差。
//3. 最小能量场大小：在遍历过程中，我们更新最小的能量场大小。
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());							// 1. 排序

	int half = (n + 1) / 2;								// 2. 求出一半的晶体数量
	int ret = INT_MAX;

	for (int left = 0, right = 0; right < n; right++)
	{
		while (right - left + 1 >= half)				// 窗口大小满足条件
		{
			ret = min(ret, v[right] - v[left]);			// 3. 记录最小能量场大小
			left++;										// 收缩左窗口
		}
	}

	cout << ret << endl;
	return 0;
}