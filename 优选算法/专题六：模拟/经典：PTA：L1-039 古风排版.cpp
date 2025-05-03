// PTA��L1-039 �ŷ��Ű�
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805091888906240&page=0

// ������ģ��
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	getchar();

	string s;
	getline(cin, s);

	int m = (s.size() + n - 1) / n;						// ����ȡ����ʽ
	int cur = 0;
	vector<vector<char>> v(n, vector<char>(m, ' '));	// ע���ʼ��Ϊ�ո�
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (cur < s.size())
			{
				v[j][i] = s[cur++];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j];
		}
		cout << endl;
	}

	return 0;
}


// �Ż���
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();								// ���ջ��з�

	string s;
	getline(cin, s);

	int m = (s.size() + n - 1) / n;				// ��������������ȡ����
	vector<string> grid(n, string(m, ' '));		// ��ʼ�� n �� m �еĿո����

	for (int i = 0; i < s.size(); ++i)
	{
		int row = i % n;						// ��ǰ�ַ�Ӧ�÷�����һ��
		int col = m - 1 - i / n;				// ��ǰ�ַ�Ӧ�÷�����һ�У���������
		grid[row][col] = s[i];
	}

	// ������
	for (const string& line : grid)
	{
		cout << line << "\n";
	}

	return 0;
}



// ���Դ��е� C++ 17 �Ż���
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	string s;
	getline(cin, s);
	string_view sv(s);								// ���⿽��

	int m = (sv.size() + n - 1) / n;
	vector<string> grid(n, string(m, ' '));

	for (int i = 0; i < sv.size(); ++i)
	{
		grid[i % n][m - 1 - i / n] = sv[i];
	}

	for (const string& line : grid)
	{
		cout << line << "\n";
	}

	return 0;
}