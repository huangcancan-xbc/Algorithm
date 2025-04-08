// 牛客：DP41 【模板】01背包
// 链接：https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e

// 方法：01 背包（动态规划）
#include <iostream>
#include <string.h>
using namespace std;

const int N = 1010;                                 // 定义最大容量
int n, V, v[N], w[N];                               // n: 物品数量, V: 背包容量, v[N]: 物品体积, w[N]: 物品价值
int dp[N][N];                                       // dp[i][j]: 表示前 i 个物品，容量 j 时的最大价值

int main()
{
    cin >> n >> V;                                  // 输入物品数量 n 和背包总容量 V
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];                        // 读取每个物品的体积 v[i] 和价值 w[i]
    }

    // 第一问：求解 01 背包的最大价值（允许不装满）
    for (int i = 1; i <= n; i++)                    // 遍历所有物品
    {
        for (int j = 1; j <= V; j++)                // 遍历容量
        {
            dp[i][j] = dp[i - 1][j];                // 不选当前物品，继承上一行结果
            if (j - v[i] >= 0)                      // 当前物品能放入背包
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);   // 选或不选当前物品，取最大价值
            }
        }
    }

    cout << dp[n][V] << endl;                       // 输出最大价值

    // 第二问：求解恰好装满背包的最大价值（不可少装）
    memset(dp, 0, sizeof(dp));                      // 重置 dp 数组
    for (int j = 1; j <= V; j++)
    {
        dp[0][j] = -1;                              // 初始化：无法装满容量 j 的背包，标记为 -1
    }

    for (int i = 1; i <= n; i++)                    // 遍历所有物品
    {
        for (int j = 1; j <= V; j++)                // 遍历背包容量
        {
            dp[i][j] = dp[i - 1][j];                // 不选当前物品，继承上一行结果
            if (j - v[i] >= 0 && dp[i - 1][j - v[i]] != -1)             // 若能放入且前置状态有效
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);   // 选或不选当前物品，取最大价值
            }
        }
    }

    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;// 若无法恰好装满，输出 0，否则输出最大价值

    return 0;
}


// 两个数组实现滚动数组优化版
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n, V, v[N], w[N];
int dp[N];                                  // 普通背包（最大价值）
int full_dp[N];                             // 恰好装满时的最大价值

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    // 第一问
    // memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)     // 逆序遍历背包容量，避免覆盖未处理的小容量状态
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout << dp[V] << endl;                  // 输出最大价值

    // 第二问
    memset(full_dp, -1, sizeof(full_dp));   // 初始化为-1（无效状态）
    full_dp[0] = 0;                         // 容量为0时价值为0（有效状态）
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)     // 逆序遍历背包容量
        {
            // 如果 j-v[i] 可达，则更新当前状态
            if (full_dp[j - v[i]] != -1)
            {
                full_dp[j] = max(full_dp[j], full_dp[j - v[i]] + w[i]);
            }
        }
    }

    cout << (full_dp[V] == -1 ? 0 : full_dp[V]) << endl;    // 输出结果：若不可达则输出0，否则输出最大价值

    return 0;
}


// 一维 DP 数组优化版
#include <iostream>
#include <string.h>
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
        for (int j = V; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

        }
    }

    cout << dp[V] << endl;

    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= V; j++)
    {
        dp[j] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)
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