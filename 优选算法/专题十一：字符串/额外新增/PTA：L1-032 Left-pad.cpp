// PTA��L1-032 Left-pad
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805100684361728&page=0

// �������ַ���ģ��
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	char ch;
	cin >> n >> ch;

	// ������뻺�����еĻ��з�
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