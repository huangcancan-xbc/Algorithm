// 牛客：DP42 【模板】完全背包
// 链接：https://www.nowcoder.com/practice/237ae40ea1e84d8980c1d5666d1c53bc

// 方法：完全背包（动态规划）
#include <iostream>
#include <cstring>                      // #include <string.h> 也可以，引入库函数，用于 memset 初始化
using namespace std;

const int N = 1010;                     // 定义最大物品数量 N
int n, V, v[N], w[N];                   // n：物品数量，V：背包容量，v[i]：第 i 个物品的体积，w[i]：第 i 个物品的价值
int dp[N][N];                           // 建立 DP 数组

int main()
{
    cin >> n >> V;                      // 读取物品数量 n 和背包容量 V
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];            // 读取每个物品的体积 v[i] 和价值 w[i]
    }

    // **第一遍 DP 计算最大价值**
    for (int i = 1; i <= n; i++)        // 遍历物品
    {
        for (int j = 0; j <= V; j++)    // 遍历背包容量
        {
            dp[i][j] = dp[i - 1][j];    // 不选当前物品，继承前 i-1 个物品的最大价值
            if (j >= v[i])              // 当前容量 j 能装下物品 i
            {
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);   // 选当前物品，更新最大价值
            }
        }
    }

    cout << dp[n][V] << endl;           // 输出第一遍 DP 计算的最大价值

    // **初始化 DP 数组，准备进行第二次 DP 计算**
    memset(dp, 0, sizeof dp);           // 清空 dp 数组，重新计算
    for (int i = 1; i <= V; i++)
    {
        dp[0][i] = -1;                  // 设定 dp[0][j] = -1，表示无法用 0 个物品凑出正数容量（无效值）
    }

    // **第二遍 DP 计算**
    for (int i = 1; i <= n; i++)        // 遍历物品
    {
        for (int j = 0; j <= V; j++)    // 遍历背包容量
        {
            dp[i][j] = dp[i - 1][j];    // 不选当前物品，继承前 i-1 个物品的最优解
            if (j >= v[i] && dp[i][j - v[i]] != -1)                 // 当前容量 j 能装下物品 i，且 j-v[i] 可达
            {
                dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);   // 选当前物品，更新最大价值
            }
        }
    }

    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;                // 若 dp[n][V] == -1 说明无法装满背包，输出 0，否则输出最大价值

    return 0;
}


// 空间优化：
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, V, v[N], w[N];
int dp[N];

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= V; i++)
    {
        dp[i] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            if (dp[j - v[i]] != -1)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    cout << (dp[V] == -1 ? 0 : dp[V]) << endl;

    return 0;
}


// 代码优化：
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, V, v[N], w[N];
int dp[N];

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= V; i++)
    {
        dp[i] = -0x3f3f3f3f;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= V; j++)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

        }
    }

    cout << (dp[V] < 0 ? 0 : dp[V]) << endl;

    return 0;
}