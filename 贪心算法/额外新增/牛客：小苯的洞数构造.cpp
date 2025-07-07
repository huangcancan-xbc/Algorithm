// 牛客：小苯的洞数构造
// 链接：https://ac.nowcoder.com/acm/contest/112544/C

// 方法：贪心

//最小的正整数，尽量用洞数大的数字，位数尽量少。所以：
//洞数最多的是 8（2个洞），其次是 0, 4, 6, 9（各1个洞）
//当 k 是偶数，直接用 k / 2 个 8 拼成的数就是最小的。
//当 k 是奇数，先放一个 4（1个洞），再用尽量多的 8（2个洞）补齐剩下的偶数洞。
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        if (k == 0)
        {
            cout << "1" << endl;
            continue;
        }

        if (k % 2 == 0)
        {
            for (int i = 0; i < k / 2; ++i)
            {
                cout << "8";
            }
        }
        else
        {
            cout << "4";
            for (int i = 0; i < (k - 1) / 2; ++i)
            {
                cout << "8";
            }
        }
        cout << endl;
    }

    return 0;
}