//洛谷：P8763 [蓝桥杯 2021 国 ABC] 异或变换
//链接：https://www.luogu.com.cn/problem/P8763
//参考：https://blog.csdn.net/weixin_45775703/article/details/124873747?spm=1001.2014.3001.5502


//方法：数学找规律，找 “周期” 循环
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long long n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    // 找 “周期” 循环,最终的规律是当大于等于n的一个2的整数次幂情况下，必定存在循环。
    long long cnt = 1;
    while (cnt < n)
    {
        cnt *= 2;
    }
    t = t % cnt;

    while (t--) 
    {
        for (long long i = n - 1; i >= 1; i--)
        {
            s[i] = (s[i - 1] - '0') ^ (s[i] - '0') + '0';
        }
    }

    cout << s << endl;

    return 0;
}