// 牛客：ICPC Medal
// 链接：https://ac.nowcoder.com/acm/contest/129231/B

// 方法：模拟
#include <iostream>
using namespace std;

int main()
{
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long j = a;    // 金
    long long yy = b;    // 银
    long long t = c;    // 铜

    while (t >= x || yy >= y)
    {
        // 铜牌合成银牌
        yy += t / x;
        t %= x;

        // 银牌合成金牌
        long long v1 = yy / y;
        j += v1;
        t += v1;  // 合成金牌掉落铜牌
        yy %= y;
    }

    cout << j << endl;
    return 0;
}