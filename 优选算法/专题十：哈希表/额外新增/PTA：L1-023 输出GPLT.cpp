// PTA：L1-023 输出GPLT
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805113036587008&page=0

// 方法：哈希表
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	string s;
	cin >> s;

	unordered_map<char, int> hash;
	for (auto x : s)
	{
		if (x == 'g' || x == 'G')
		{
			hash['G']++;
		}
		if (x == 'p' || x == 'P')
		{
			hash['P']++;
		}
		if (x == 'l' || x == 'L')
		{
			hash['L']++;
		}
		if (x == 't' || x == 'T')
		{
			hash['T']++;
		}
	}

	const char* ch = "GPLT";

	// 只要还有字母未输出完
	while (hash['G'] || hash['P'] || hash['L'] || hash['T'])
	{
		// 按 GPLT 顺序检查
		for (int i = 0; i < 4; i++)
		{
			if (hash[ch[i]])
			{
				cout << ch[i];
				hash[ch[i]]--;
			}
		}
	}

	return 0;
}


// 数组优化：
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;

	int hash[4] = { 0 };
	for (auto x : s)
	{
		if (x == 'G' || x == 'g')
		{
			hash[0]++;
		}
		else if (x == 'P' || x == 'p')
		{
			hash[1]++;
		}
		else if (x == 'L' || x == 'l')
		{
			hash[2]++;
		}
		else if (x == 'T' || x == 't')
		{
			hash[3]++;
		}
	}

	const char* ch = "GPLT";
	while (hash[0] + hash[1] + hash[2] + hash[3] > 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (hash[i] > 0)
			{
				cout << ch[i];
				hash[i]--;
			}
		}
	}

	return 0;
}