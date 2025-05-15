//牛客：	既然回文数会浪费非常长的时间那不如直接一行秒杀他？
//https://ac.nowcoder.com/acm/contest/97845/K
//参赛密码：517acm


//方法一：将字符串反转进行比较
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is(int x)
{
    string s = to_string(x);
    string ss = s;

    reverse(ss.begin(), ss.end());

    return s == ss;
}

int main()
{
    int n = 0;
    cin >> n;

    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (is(i))
        {
            ret++;
        }
    }

    cout << ret;
    return 0;
}




//方法二：双指针
#include <iostream>
#include <string>
using namespace std;

bool is(int x)
{
    if (x < 0 || x % 10 == 0)
    {
        return false;
    }

    string s = to_string(x);

    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left++] != s[right--])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 0;
    cin >> n;

    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (is(i))
        {
            ret++;
        }
    }

    cout << ret;
    return 0;
}