//晴问：最大晶宽体
//链接：https://sunnywhy.com/contest/145/problem/A


//方法：哈希表
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int hash[26] = { 0 };

    while (n--)
    {
        char g = 0;
        int l = 0, w = 0;
        cin >> g >> l >> w;

        hash[g - 'A'] += l * w;                         // 将字符转换为数组索引
    }

    int num = 0;
    int ch = 0;                                         // 使用整数类型存储索引
    for (int i = 0; i < 26; i++)
    {
        // 如果当前晶体的面积大于最大面积，或者面积相同且字符小于当前晶体的字符，则更新最大面积和字符
        if (hash[i] > num || (hash[i] == num && i < ch))
        {
            num = hash[i];
            ch = i;
        }
    }

    cout << (char)('A' + ch) << " " << num << endl;     // 将索引转换回字符

    return 0;
}





#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    map<char, int> map;

    while (n--)
    {
        char g = 0;
        int l = 0, w = 0;
        cin >> g >> l >> w;

        map[g] += l * w;                                // 累加面积到对应能量场
    }

    char ch = 'A';                                      // 记录最大能量场的字符
    int num = 0;

    for (const auto& x : map)
    {
        if (x.second > num || (x.second == num && x.first < ch))
        {
            num = x.second;
            ch = x.first;
        }
    }

    cout << ch << " " << num << endl;

    return 0;
}





#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main() 
{
    int n;
    cin >> n;

    unordered_map<string, int> map;                     // 存储每个能量场的能量指数

    // 遍历每个晶体的数据
    for (int i = 0; i < n; ++i) 
    {
        string g;
        int l, w;
        cin >> g >> l >> w;

        map[g] += l * w;                                // 计算当前晶体的面积，并累加到对应的能量场
    }

    // 初始化变量，记录最大能量指数和对应的能量场
    string ch;
    int ret = -1;

    for (const auto& x : map) 
    {
        const string& g = x.first;
        int temp = x.second;

        // 比较能量指数，如果相同则选字典序较小的
        if (temp > ret || (temp == ret && g < ch)) 
        {
            ret = temp;
            ch = g;
        }
    }

    cout << ch << " " << ret << endl;

    return 0;
}





#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int hash[26] = { 0 };

    while (n--)
    {
        string s;
        cin >> s;
        char g = s[0];
        int l, w;
        cin >> l >> w;

        hash[g - 'A'] += l * w;
    }

    int num = 0;
    int ret = hash[0];

    for (int i = 1; i < 26; i++)
    {
        if (hash[i] > ret || (hash[i] == ret && ('A' + i) < ('A' + num)))
        {
            ret = hash[i];
            num = i;
        }
    }

    cout << (char)('A' + num) << " " << ret << endl;

    return 0;
}