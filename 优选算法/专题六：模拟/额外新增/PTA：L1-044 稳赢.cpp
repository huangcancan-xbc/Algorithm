// PTA��L1-044 ��Ӯ
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805086365007872&page=0

// ������ģ��
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k;
	cin >> k;
	string s;
	int i = 0;

	while (cin >> s && s != "End")
	{
		if (i == k)
		{
			cout << s << endl;
			i = 0;
		}
		else
		{
			if (s == "ChuiZi")
			{
				cout << "Bu" << endl;
			}
			else if (s == "JianDao")
			{
				cout << "ChuiZi" << endl;
			}
			else if (s == "Bu")
			{
				cout << "JianDao" << endl;
			}

			i++;
		}
	}

	return 0;
}



// ����д����
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int k;
	cin >> k;
	string s;
	int i = 0;

	while (cin >> s)
	{
		if (s == "End")
		{
			return 0;
		}

		if (i == k)
		{
			cout << s << endl;
			i = 0;
		}
		else
		{
			if (s == "ChuiZi")
			{
				cout << "Bu" << endl;
			}
			else if (s == "JianDao")
			{
				cout << "ChuiZi" << endl;
			}
			else if (s == "Bu")
			{
				cout << "JianDao" << endl;
			}

			i++;
		}
	}

	return 0;
}