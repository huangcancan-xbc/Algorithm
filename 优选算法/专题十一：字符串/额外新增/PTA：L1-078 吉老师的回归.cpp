// PTA��L1-078 ����ʦ�Ļع�
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652357&page=0

// �������ַ���
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	getchar();

	string ret = "Wo AK le";

	for (int i = 0; i < n; ++i)
	{
		string s;
		getline(cin, s);

		if (s.find("easy") != string::npos || s.find("qiandao") != string::npos)
		{
			continue;
		}

		if (m == 0)
		{
			ret = s;
		}

		if (m > 0)
		{
			m--;
		}
	}

	cout << ret << endl;

	return 0;
}