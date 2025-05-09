// PTA：L1-101 别再来这么多猫娘了！
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1781658570803388420&page=1

// 方法：字符串的灵活运用
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    string s[n];                                // 存违禁词
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int k;
    cin >> k;
    string str;                                 // 存文本
    getchar();
    getline(cin, str);                          // 用 getline 读取一整行
    int count = 0;                              // 记录违禁词个数

    for (int j = 0; j < n; j++)                 // 遍历所有违禁词
    {
        // 遍历文本，查找每个违禁词
        while ((int)str.find(s[j]) != -1)       // while(str.find(s[j]) != str.npos)
        {
            int pos = (int)str.find(s[j]);      // 违禁词首字母的位置
            int len = s[j].size();              // 违禁词的长度
            str.replace(pos, len, "^_^");       // 违禁词替换为任意字符（最开始使用^^^，没想到有一个样例过不了，直接换成了 ^_^）
            count++;                            // 违禁词个数加1
        }
    }

    if (count < k)
    {
        for (int i = 0; i < count; i++)         // while((int)str.find("-_-") != -1)
        {
            int pos = str.find("^_^");
            str.replace(pos, 3, "<censored>");  // 将刚刚替换的字符再替换为 "He Xie Ni Quan Jia!"
        }

        cout << str << endl;
    }
    else
    {
        cout << count << endl;
        cout << "He Xie Ni Quan Jia!";
    }

    return 0;
}