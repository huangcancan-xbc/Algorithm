// PTA：L1-019 谁先倒
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805118568873984&page=0

// 方法：模拟
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int jia = 0, yi = 0;
	cin >> jia >> yi;

	int t = 0;
	cin >> t;

	int counta = 0, countb = 0;
	vector<vector<int>> v(t, vector<int>(5, 0));
	for (int i = 0; i < t; i++)
	{
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];
		v[i][4] = v[i][0] + v[i][2];

		if (v[i][1] == v[i][4] && v[i][3] != v[i][4])
		{
			counta++;
		}

		if (v[i][1] != v[i][4] && v[i][3] == v[i][4])
		{
			countb++;
		}

		if (counta > jia)
		{
			cout << "A" << endl << countb << endl;
			return 0;
		}
		else if (countb > yi)
		{
			cout << "B" << endl << counta << endl;
			return 0;
		}
	}

	return 0;
}


// 写法改进/优化：
#include <iostream>
using namespace std;
int main()
{
	int jia, yi;
	cin >> jia >> yi;

	int n;
	cin >> n;

	int counta = 0, countb = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sum = a + c;

		bool a_lose = (b == sum); // 甲是否输
		bool b_lose = (d == sum); // 乙是否输

		// 只有一人输时才喝酒
		if (a_lose && !b_lose)
		{
			counta++;
		}
		else if (!a_lose && b_lose)
		{
			countb++;
		}

		// 检查是否有人倒下
		if (counta > jia)
		{
			cout << "A" << endl << countb << endl;
			return 0;
		}
		if (countb > yi)
		{
			cout << "B" << endl << counta << endl;
			return 0;
		}
	}

	return 0;
}