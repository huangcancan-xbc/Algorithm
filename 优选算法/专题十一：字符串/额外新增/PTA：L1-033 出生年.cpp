// PTA��L1-033 ������
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805099426070528&page=0

// �������ַ������������⣩
#include <iostream>
#include <string>
using namespace std;

int is(string x, int n)
{
	int hash[10] = { 0 };
	while (x.size() < 4)
	{
		x = "0" + x;
	}

	for (int i = 0; i < 4; i++)
	{
		hash[x[i] - '0']++;
	}

	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (hash[i])
		{
			count++;
		}
	}

	return count == n;
}

int main()
{
	string s;
	int n;

	cin >> s >> n;

	while (s.size() < 4)
	{
		s = "0" + s;
	}

	int age = 0;
	string ret;

	// �ӵ㣨�ڶ������Ե�Ŀӣ�����Ŀֻ˵�� y �ķ�Χ��[1,3000]���������� x �ķ�Χ������Ҫ���� x �ķ�Χ���������Ҫ��һ�㣡����ͬ��
	for (int i = stoi(s); i <= 3050; i++)
	{
		if (is(to_string(i), n))
		{
			ret = to_string(i);
			while (ret.size() < 4)
			{
				ret = "0" + ret;
			}

			cout << age << " " << ret << endl;
			return 0;
		}

		age++;
	}

	return 0;
}



// д���Ż���
#include <iostream>
#include <string>
using namespace std;

bool is(string year, int n)
{
	bool hash[10] = { false };
	int count = 0;

	for (char c : year)
	{
		int x = c - '0';
		if (!hash[x])
		{
			hash[x] = true;
			count++;
		}
	}

	return count == n;
}

int main()
{
	string s;
	int n;

	cin >> s >> n;

	while (s.size() < 4)
	{
		s = "0" + s;
	}

	int star = stoi(s);
	int age = 0;
	for (int y = star; y <= 3050; y++)
	{
		string year = to_string(y);
		while (year.size() < 4)
		{
			year = "0" + year;
		}

		if (is(year, n))
		{
			cout << (y - star) << " " << year << endl;
			return 0;
		}
	}

	return 0;
}