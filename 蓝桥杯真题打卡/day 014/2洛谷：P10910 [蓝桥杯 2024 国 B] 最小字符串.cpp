//洛谷：P10910 [蓝桥杯 2024 国 B] 最小字符串
//链接：https://www.luogu.com.cn/problem/P10910


//方法：字符串/贪心
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	string ret;								// 结果字符串
	sort(t.begin(), t.end());				// 排序待插入的字符
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		while (t[k] < s[i] && k < m)		// 如果待插入的字符比字符串 S 当前的字符小，就将该字符插入到结果中
		{
			if (k >= m || t[k] > s[i])
			{
				break;
			}

			ret += t[k++];
		}
		ret += s[i];						// 再将当前字符加入到结果中
	}

	for (int i = k; i < m; i++)				// 将剩余的字符加如到结果中
	{
		ret += t[i];
	}

	for (auto x : ret)						// 遍历输出结果
	{
		cout << x;
	}
	return 0;
}





#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	sort(t.begin(), t.end());				// 为要插入的字符进行排序
	int k = 0;

	for (int i = 0; i < n; i++)
	{
		while (t[k] < s[i] && k < m)		// 如果要插入的字符比字符串 S 当前的字符小，直接输出
		{
			if (k >= m || t[k] > s[i])		// 如果已经超过待插入字符的个数，或者插入字符比当前字符大，则退出循环
			{
				break;
			}

			cout << t[k++];
		}
		cout << s[i];						// 输出完“小”字符，再输出当前字符
	}

	for (int i = k; i < m; i++)
	{
		cout << t[i];						// 比较完所有字符后，如果还有剩余的字符，直接输出
	}

	return 0;
}