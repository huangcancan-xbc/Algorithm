//牛客：小数字
//链接：https://ac.nowcoder.com/acm/contest/99458/C

//方法：贪心
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int t;
    cin >> t;

    while (t--) 
    {
        int n, m;
        cin >> n >> m;

        while (m > 0 && n > 1) 
        {
            if (n > 2) 
            {
                n = ceil(sqrt(n));      // 优先开根号
            }
            else 
            {
                n = (n + 1) / 2;        // 如果 n <= 2，优先做除 2 操作
            }

            m--;                        // 操作次数减 1
        }

        n -= m;                         // 如果 m 还没有结束，剩下的都是减 1 操作

        cout << n << endl;
    }

    return 0;
}
