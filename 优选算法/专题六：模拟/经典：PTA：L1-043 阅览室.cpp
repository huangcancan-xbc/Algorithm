// PTA：L1-043 阅览室
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805087447138304&page=0

// 方法：模拟
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int v[1001][2] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int shuhao;
		char val;
		int hh, mm;
		int time = 0;
		int count = 0;
		scanf("%d %c %d:%d", &shuhao, &val, &hh, &mm);

		while (shuhao)
		{
			if (val == 'S')
			{
				v[shuhao][0] = 1;
				v[shuhao][1] = hh * 60 + mm;
			}
			else if (val == 'E' && v[shuhao][0])
			{
				count++;
				time += hh * 60 + mm - v[shuhao][1];
				v[shuhao][0] = 0;
			}

			scanf("%d %c %d:%d", &shuhao, &val, &hh, &mm);
		}

		if (count == 0)
		{
			cout << "0 0" << endl;
		}
		else
		{
			printf("%d %.0f\n", count, (float)time / count);	// 这个四舍五入挺好用
		}

	}

	return 0;
}