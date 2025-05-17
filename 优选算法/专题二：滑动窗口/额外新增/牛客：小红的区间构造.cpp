//牛客：小红的区间构造
//链接：https://ac.nowcoder.com/acm/contest/99277/B


//方法一：滑动窗口

//能过 90% 的测试用例，剩下的用例超时
#include <iostream>
using namespace std;
int main()
{
    long long n, k, x;
    cin >> n >> k >> x;

    long long left = x, right = x + k - 1;

    // 通过一个 lambda 表达式定义一个函数 count，用于计算给定区间 [l, r] 内有多少个 x 的倍数
    auto count = [&](long long l, long long r) {
        return r / x - (l - 1) / x;
        };

    while (right <= 2 * 1e9)
    {
        if (count(left, right) == n)
        {
            cout << left << " " << left + k - 1;
            return 0;
        }
        left++;
        right++;
    }

    cout << -1 << endl;
    return 0;
}



//方法二：数学
#include <iostream>
using namespace std;
int main()
{
    long long n, k, x;
    cin >> n >> k >> x;

    if (k < (n - 1) * x + 1)            // 如果区间长度 k 小于最小需要的长度，输出 -1
    {
        cout << -1;
    }
    else
    {
        cout << x << " " << n * x;      // 使用数学推导直接得到 l 和 r
    }

    return 0;
}