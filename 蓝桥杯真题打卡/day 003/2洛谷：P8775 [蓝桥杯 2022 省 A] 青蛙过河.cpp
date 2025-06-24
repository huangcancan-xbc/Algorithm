//洛谷：P8775 [蓝桥杯 2022 省 A] 青蛙过河
//链接：https://www.luogu.com.cn/problem/P8775


//方法：二分 + 前缀和 + 贪心
//解题思路：
//- 前缀和：使用前缀和数组 sum 来快速计算数组任意子区间的和。
//	前缀和数组 sum[i] 存储的是从数组第一个元素到第 i 个元素的和。
//	通过前缀和，可以在常数时间内计算任意子区间的和。
//- 二分查找：我们需要找到最小的 mid，使得从某个位置开始，长度为 mid 的子数组的和至少为 2 * x。
//	这就涉及到在[1, n - 1] 范围内进行二分查找。通过二分查找，我们逐渐缩小搜索范围，最终找到最小的 mid。
//时间复杂度：O(nlogn)
#include <iostream>
#include <vector>
using namespace std;
int n = 0, x = 0;

bool check(int mid, int x, vector<int>& v, vector<int>& sum)
{
	// 遍历所有可能的子数组长度为 mid，检查其和是否满足条件
	for (int i = mid; i < n; i++)
	{
		if (sum[i] - sum[i - mid] < 2 * x)		// 如果某个区间和小于 2 * x
		{
			return false;						// 则返回 false
		}
	}

	return true;								// 否则返回 true
}

int main()
{
	cin >> n >> x;

	vector<int> v(n - 1), sum(n, 0);			// v 数组是输入的数组，sum 数组存储前缀和，注意 sum[0] 初始化0
	for (int i = 0; i < n - 1; i++)
	{
		cin >> v[i];							// 用数组存储数据
	}

	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + v[i - 1];			// 构建前缀和数组，从 sum[1] 开始
	}

	int left = 1, right = n;					// 定义左右指针


	while (left < right)						// 二分查找的区间是 [1, n]
	{
		int mid = left + (right - left) / 2;	// 中间位置（防溢出）
		if (check(mid, x, v, sum))
		{
			right = mid;						// 右指针向左移动
		}
		else
		{
			left = mid + 1;						// 左指针向右移动
		}
	}

	cout << left;								// 输出最小的 mid

	return 0;
}