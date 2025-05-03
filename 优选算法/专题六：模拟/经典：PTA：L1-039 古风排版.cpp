// PTA：L1-039 古风排版
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805091888906240&page=0

// 方法：模拟
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

	int m = (s.size() + n - 1) / n;						// 向上取整公式
	int cur = 0;
	vector<vector<char>> v(n, vector<char>(m, ' '));	// 注意初始化为空格
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


// 优化：
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();								// 吸收换行符

	string s;
	getline(cin, s);

	int m = (s.size() + n - 1) / n;				// 计算列数（向上取整）
	vector<string> grid(n, string(m, ' '));		// 初始化 n 行 m 列的空格矩阵

	for (int i = 0; i < s.size(); ++i)
	{
		int row = i % n;						// 当前字符应该放在哪一行
		int col = m - 1 - i / n;				// 当前字符应该放在哪一列（从右往左）
		grid[row][col] = s[i];
	}

	// 输出结果
	for (const string& line : grid)
	{
		cout << line << "\n";
	}

	return 0;
}



// 来自大佬的 C++ 17 优化：
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
	string_view sv(s);								// 避免拷贝

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