// PTA：L1-011 A-B
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805130426171392&page=0

// 方法：哈希表
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);

	unordered_map<int, int> hash;
	for (auto x : b)
	{
		hash[x]++;
	}

	for (auto x : a)
	{
		if (hash[x])
		{
			continue;
		}

		cout << x;
	}

	cout << endl;

	return 0;
}


// 数组优化
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    bool hash[256] = { false }; // 标记B中的字符是否存在

    // 遍历B，标记存在的字符
    for (char c : b)
	{
        hash[(unsigned char)c] = true;
    }

    // 遍历A，输出未在B中出现的字符
    for (char c : a)
	{
        if (!hash[(unsigned char)c])
		{
            cout << c;
        }
    }

    cout << endl;

    return 0;
}