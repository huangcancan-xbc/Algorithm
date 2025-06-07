// 洛谷：U535982 J-A 小梦的AB交换
// 链接：https://www.luogu.com.cn/problem/U535982

// 方法：贪心、模拟、枚举
// 1. ABABAB...：奇数位置为A，偶数位置为B。需要奇数位置全为A，需要 n - counta 次交换
// 2. BABABA...：奇数位置为B，偶数位置为A。需要奇数位置全为B，奇数位置有 counta 个A需要被替换为B，需要 counta 次交换
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;

        string s;
        cin >> s;

        int counta = 0;
        for (int i = 1; i < 2 * n; i += 2)
        {
            if (s[i] == 'A')
            {
                counta++;
            }
        }

        cout << min(n - counta, counta) << endl;
    }

    return 0;
}