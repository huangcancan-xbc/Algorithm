//牛客：小红的双生串
//链接：https://ac.nowcoder.com/acm/contest/99784/B


//方法：哈希表
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int hash[26] = {0};

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    int half = n / 2;                       // 字符串长度的一半长度为half

    // 1. 统计字符串左半部分的字符出现的次数
    unordered_map<char, int> left;
    for (int i = 0; i < half; i++)
    {
        left[s[i]]++;
    }

    // 2. 统计字符串右半部分的字符出现的次数
    unordered_map<char, int> right;
    for (int i = half; i < n; i++)
    {
        right[s[i]]++;
    }

    // 3. 计算左半部分出现最多次的字符数
    int max1 = 0;
    for (auto& [a, b] : left)
    {
        max1 = max(max1, b);
    }

    // 4. 计算右半部分出现最多次的字符数
    int max2=0;
    for (auto& [a, b] : right)
    {
        max2 = max(max2, b);
    }

    int ret = half - max1 + half - max2;    // 计算最小操作次数

    cout << ret << endl;

    return 0;
}