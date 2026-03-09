// 牛客：Unique Number
// 链接：https://ac.nowcoder.com/acm/contest/129231/C

// 方法：贪心
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long cur = v[0];
        int ret = 1;

        for (int i = 1; i < n; i++)
        {
            cur = min(cur - 1, v[i]);

            if (cur < 0)
            {
                break;
            }

            ret++;
        }
        cout << ret << endl;
    }
    return 0;
}