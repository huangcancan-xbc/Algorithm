// 牛客：小红的数组取数
// 链接：https://ac.nowcoder.com/acm/contest/117763/B

// 方法：找规律
//答案就是：A 数组的最小值下标 和 B 数组的最大值下标。

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    int minA = a[1], idxA = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] < minA)
        {
            minA = a[i];
            idxA = i;
        }
    }

    int maxB = b[1], idxB = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (b[i] > maxB)
        {
            maxB = b[i];
            idxB = i;
        }
    }

    cout << idxA << " " << idxB << "\n";
    return 0;
}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    int idxA = min_element(a.begin() + 1, a.end()) - a.begin(); // A 数组的最小值下标
    int idxB = max_element(b.begin() + 1, b.end()) - b.begin(); // B 数组的最大值下标

    cout << idxA << " " << idxB << endl;
    return 0;
}