//晴问：10026. 省略元音
//链接：https://sunnywhy.com/problem/10026


//方法：字符串处理
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isvowel(char c)
{
	c = tolower(c);							// 将字符转换为小写，这样大写也可以用小写进行判断
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main()
{
	string s;
	getline(cin, s);						// 读取一行字符串

	stringstream ss(s);						// 将字符串流化为stringstream对象
	string word;
	bool isfirst = true;					// 标记是否是第一个单词

	while (ss >> word)
	{
		if (!isfirst)
		{
			cout << " ";					// 在每个单词之间添加空格，除第一个单词外（保证格式正确）
		}

		bool flag = isvowel(word[0]);		// 判断第一个字母是否为元音

		// 分类讨论
		if (flag)
		{
			cout << word[0];
			for (int i = 1; i < word.size(); i++)
			{
				if(!isvowel(word[i]))
				{
					cout << word[i];
				}
			}
		}
		else
		{
			for (int i = 0; i < word.size(); i++)
			{
				if (!isvowel(word[i]))
				{
					cout << word[i];
				}
			}
		}

		isfirst = false;					// 标记下一个单词不是第一个单词
	}

	return 0;
}