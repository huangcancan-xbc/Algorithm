// 牛客：小苯的Z串匹配
// 链接：https://ac.nowcoder.com/acm/contest/105623/C

// 方法一：暴力枚举
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long n = 0;
        cin >> n;
        long long ret = 0;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        string s;
        cin >> s;

        for (long long i = 0; i < n; i++)
        {
            if (s[i] == '>' && v[i] <= 0)
            {
                v[i] = 10;
                ret++;
            }

            if (s[i] == '<' && v[i] >= 0)
            {
                v[i] = -10;
                ret++;
            }

            if (s[i] == 'Z')
            {
                if (v[i] * v[i - 1] <= 0)
                {
                    v[i] = v[i - 1];
                    ret++;
                }
            }
        }

        cout << ret << endl;
    }

    return 0;
}


// 方法二：动态规划
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        string s;
        cin >> s;

        vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

        if (s[0] == '<')
        {
            dp[0][0] = a[0] < 0 ? 0 : 1;
            dp[0][1] = INT_MAX;
        }
        else if (s[0] == '>')
        {
            dp[0][1] = a[0] > 0 ? 0 : 1;
            dp[0][0] = INT_MAX;
        }

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '<')
            {
                int cost = (a[i] < 0) ? 0 : 1;
                int flag = min(dp[i - 1][0], dp[i - 1][1]);
                if (flag != INT_MAX)
                {
                    dp[i][0] = flag + cost;
                }
            }
            else if (s[i] == '>')
            {
                int cost = (a[i] > 0) ? 0 : 1;
                int flag = min(dp[i - 1][0], dp[i - 1][1]);
                if (flag != INT_MAX)
                {
                    dp[i][1] = flag + cost;
                }
            }
            else if (s[i] == 'Z')
            {
                int const1 = (a[i] < 0) ? 0 : 1;
                if (dp[i - 1][0] != INT_MAX)
                {
                    dp[i][0] = dp[i - 1][0] + const1;
                }

                int const2 = (a[i] > 0) ? 0 : 1;
                if (dp[i - 1][1] != INT_MAX)
                {
                    dp[i][1] = dp[i - 1][1] + const2;
                }
            }
        }

        int ret = min(dp[n - 1][0], dp[n - 1][1]);
        cout << ret << endl;
    }

    return 0;
}