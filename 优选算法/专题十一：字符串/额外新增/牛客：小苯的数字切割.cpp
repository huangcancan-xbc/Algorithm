// 牛客：小苯的数字切割
// 链接：https://ac.nowcoder.com/acm/contest/105623/B

// 方法一：字符串分割
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string n;
        cin >> n;

        long long max_sum = 0;

        for (int i = 1; i < n.size(); ++i)
        {
            string left = n.substr(0, i);
            string right = n.substr(i);

            long long sum = stoll(left) + stoll(right);

            max_sum = max(max_sum, sum);
        }

        cout << max_sum << endl;
    }

    return 0;
}


// 方法二：数学方法
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int max_sum = 0;
        int temp = n;
        int divisor = 10;

        while (divisor <= n)
        {
            int left = n / divisor;
            int right = n % divisor;
            max_sum = max(max_sum, left + right);
            divisor *= 10;
        }

        cout << max_sum << endl;
    }

    return 0;
}