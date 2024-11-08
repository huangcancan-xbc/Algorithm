//牛客：DP35 【模板】二维前缀和
//https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=2023819&ru=/exam/oj&qru=/ta/dynamic-programming/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196


//方法一：暴力解法-->模拟
#include <iostream>
using namespace std;

const int N = 1002;
int arr[N][N];                    // 定义原始矩阵

int main()
{
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;           // 输入矩阵的行数n，列数m，以及查询次数q

    // 输入矩阵元素
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 处理每个查询
    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;           // 输入每个查询的坐标范围
        long long sum = 0;                     // 初始化子矩阵的元素和

        // 暴力累加查询范围内的每个元素
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                sum += arr[i][j];              // 将范围内每个元素加到sum
            }
        }

        cout << sum << endl;                   // 输出当前查询的元素和
    }

    return 0;
}





//方法二：前缀和
//时间复杂度：O(m*n)+O(q)

//算法原理：
//1.预处理出来一个前缀和矩阵
//2.使用前缀和矩阵
//前缀和主要公式：
//前缀和的主要公式是：dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] （当前位置的元素值 + 上方元素的前缀和 + 左方元素的前缀和 - 左上角元素的前缀和）
//   子矩阵的和公式：dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] （右下角元素的前缀和 - 右上角元素的前缀和 - 左下角元素的前缀和 + 左上角元素的前缀和）

#include <iostream>
using namespace std;

const int N = 1002;             // 定义二维数组的最大大小
int arr[N][N];                  // 原始输入矩阵
long long dp[N][N];             // 前缀和矩阵，用于存储二维前缀和

int main()
{
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;         // 输入矩阵行数n，列数m，以及查询次数q

    // 输入矩阵元素
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 计算前缀和矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = arr[i][j]                 // 当前元素值
                + dp[i - 1][j]                   // 上方元素的前缀和
                + dp[i][j - 1]                   // 左方元素的前缀和
                - dp[i - 1][j - 1];              // 减去重复计算的左上角元素
        }
    }

    // 处理每个查询
    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;             // 输入查询的坐标范围
        cout << dp[x2][y2]                       // 右下角前缀和
            - dp[x1 - 1][y2]                     // 减去上方的矩形区域
            - dp[x2][y1 - 1]                     // 减去左方的矩形区域
            + dp[x1 - 1][y1 - 1]                 // 加回左上角多减的区域
            << endl;
    }

    return 0;
}





//二维前缀和+STL的写法（推荐）：
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;           // 输入矩阵的行数n，列数m，以及查询次数q

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));

    // 输入矩阵元素
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // 计算前缀和矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    // 处理每个查询
    int x1, y1, x2, y2;
    while (q--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}





//很早之前用C语言的写法：
#include <stdio.h>
#define int long long  
#define N 10000       

int a[N][N], b[N][N]; 

int main()
{
    int n, m, q;
    scanf("%lld %lld %lld", &n, &m, &q);

    // 构建前缀和矩阵 b
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &a[i][j]);                        // 读入每个元素到矩阵 a 中

            // 计算位置 (i, j) 的前缀和 b[i][j]：
            // - 加上当前位置元素 "a[i][j]"
            // - 加上从上方累积的前缀和 "b[i - 1][j]" 和左边的 "b[i][j - 1]"
            // - 减去重复累加的部分 "b[i - 1][j - 1]"
            b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    // 处理每一个查询以计算子矩阵的和
    while (q--)
    {
        int x1, y1, x2, y2;
        
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);   // 读取子矩阵的左上角 (x1, y1) 和右下角 (x2, y2) 的坐标

        // 使用前缀和计算子矩阵和：
        // - "b[x2][y2]" 是从 (1,1) 到 (x2, y2) 的子矩阵和
        // - 减去不属于目标区域的部分： "b[x2][y1 - 1]" 和 "b[x1 - 1][y2]"
        // - 加回重叠部分 "b[x1 - 1][y1 - 1]" 来校正双重减去的部分
        printf("%lld\n", b[x2][y2] - b[x2][y1 - 1] - b[x1 - 1][y2] + b[x1 - 1][y1 - 1]);
    }

    return 0;
}
