//牛客：球格模型（简单版）
//链接：https://ac.nowcoder.com/acm/contest/99458/B


//方法：模拟
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    if (k < max(n, m))
    {
        cout << "-1" << endl;
        return 0;
    }

    vector<vector<int>> v(n, vector<int>(m, 0));
    int count = k;

    // 先填满对角线
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j && count > 0)
            {
                v[i][j] = 1;
                count--;
            }
        }
    }

    // 分类讨论：行多于列就填剩下行的第一个位置，列多于行就填剩下列的第一个位置
    if (n > m)
    {
        int x = m;
        while (count)
        {
            if (x == n - 1)
            {
                v[x][0] += count;           // 如果到了最后一行，就把剩下的 k 个都填到这个位置
                break;
            }
            v[x][0] += 1;
            count--;
            x++;
        }
    }
    else if (m > n)
    {
        int y = n;
        while (count)
        {
            if (y == m - 1)
            {
                v[0][y] += count;           // 如果到了最后一列，就把剩下的 k 个都填到这个位置
                break;
            }
            v[0][y] += 1;
            count--;
            y++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}