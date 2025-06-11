// 牛客：G-Check phone
// 链接：https://ac.nowcoder.com/acm/contest/105851/G

// 方法一：暴力匹配
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;
        int m = str.size(), j = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == str[j])
            {
                j++;
            }
            if (j == m)
            {
                break;              // 特殊情况优化（不加超时）。子串可能在原串的中间或者最前的位置，这样就能优化很多时间。
            }
        }

        if (j == m)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

    }
    return 0;
}



// 方法二：哈希表 + 二分
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, vector<int>> hash;
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]].push_back(i);                // 使用哈希表记录每个字符在 s 中的出现位置
    }

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        bool flag = true;                       // 判断 str 的所有字符是否都在 s 中出现过
        for (auto x : str)
        {
            if (hash.count(x) == 0)             // 如果 hash 表中没有字符 x
            {
                flag = false;
                cout << "No" << endl;
                break;
            }
        }

        if (flag)                               // 如果所有字符都存在，开始匹配判断子序列关系
        {
            int last_pos = -1;                  // 上一次匹配的位置

            for (auto x : str)
            {
                // 在 hash[x] 的位置列表里找到第一个大于 last_pos 的位置
                auto it = upper_bound(hash[x].begin(), hash[x].end(), last_pos);
                if (it == hash[x].end())        // 没找到，匹配失败
                {
                    flag = false;
                    cout << "No" << endl;
                    break;
                }
                last_pos = *it;                 // 更新 last_pos，继续匹配下一个字符
            }

            if (flag)
            {
                cout << "Yes" << endl;          // 如果成功匹配所有字符，输出 Yes
            }
        }
    }

    return 0;
}