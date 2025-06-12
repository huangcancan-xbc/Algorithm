// PTA：L1-032 Left-pad
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805100684361728&page=0

// 方法：字符串模拟
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char ch;
	cin >> n >> ch;

	// 清除输入缓冲区中的换行符
	// getchar();
	cin.ignore();

	string s;
	getline(cin, s);

	int len = s.size();
	if (len <= n)
	{
		int k = n - len;
		while (k--)
		{
			cout << ch;
		}
		cout << s;
	}
	else
	{
		cout << s.substr(len - n);
	}

	return 0;
}