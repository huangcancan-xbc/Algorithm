//牛客：星空探测
//链接：https://ac.nowcoder.com/acm/contest/98971/D


//方法一：暴力模拟
#include <iostream>
#include <vector>
using namespace std;

int dp(vector<vector<char>>& v, int x, int y)
{
    int ret = 0;

    // 周围 8 个位置的 '#' 的数量
    if (v[x - 1][y - 1] == '#')
    {
        ret++;
    }
    if (v[x - 1][y] == '#')
    {
        ret++;
    }
    if (v[x - 1][y + 1] == '#')
    {
        ret++;
    }
    if (v[x][y - 1] == '#')
    {
        ret++;
    }
    if (v[x][y + 1] == '#')
    {
        ret++;
    }
    if (v[x + 1][y - 1] == '#')
    {
        ret++;
    }
    if (v[x + 1][y] == '#')
    {
        ret++;
    }
    if (v[x + 1][y + 1] == '#')
    {
        ret++;
    }

    return ret;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    // 在输入矩阵时，考虑在矩阵周围包裹一圈虚拟边界（哨兵值），这样在 dp 函数中可以省略越界检查
    vector<vector<char>> v(n + 2, vector<char>(m + 2, '.'));


    // 以下的循环均从虚拟边界开始，因此不需要考虑边界问题！
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i][j] == '.')
            {
                v[i][j] = dp(v, i, j) + '0';
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}




//方法二：暴搜优化
#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;

// 计算周围 '#' 的数量
int dp(vector<vector<char>>& v, int x, int y)
{
    int ret = 0;
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) // 遍历8个方向
    {
        int nx = x + dx[i], ny = y + dy[i];
        // 检查边界
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == '#')
        {
            ret++;
        }
    }

    return ret;
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                v[i][j] = '0' + dp(v, i, j);        // 将数字转换为字符
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}