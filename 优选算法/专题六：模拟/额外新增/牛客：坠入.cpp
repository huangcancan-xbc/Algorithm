// 牛客：坠入
// 链接：https://ac.nowcoder.com/acm/contest/106318/C

// 方法：数学模拟
#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        // 横坐标
        if (((b1 + c1) / 2 == a1) || ((a1 + c1) / 2 == b1) || ((a1 + b1) / 2 == c1))
        {
            cout << "YES" << endl;
            continue;
        }
        if (((b2 + c2) / 2 == a2) || ((a2 + c2) / 2 == b2) || ((a2 + b2) / 2 == c2))
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}