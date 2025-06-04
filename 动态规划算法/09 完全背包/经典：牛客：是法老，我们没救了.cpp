// 牛客：是法老，我们没救了
// 链接：https://ac.nowcoder.com/acm/contest/98971/H

// 方法：动态规划
//1. 状态表示
//定义 dp[i][j] 表示考虑前 i 个数字时，和为 j 的子序列的数量。这里的 i 可以从 0 到 n，j 可以从 0 到 target。
//
//2. 状态转移方程
//对于每个数字 nums[i - 1]（因为数组索引从 0 开始），我们有两个选择：
//    1. 不选这个数字：那么 dp[i][j] 的值等于 dp[i - 1][j]，即不考虑当前数字时和为 j 的子序列数量。
//    2. 选这个数字：如果 j >= nums[i - 1]，那么 dp[i][j] 的值还需要加上 dp[i - 1][j - nums[i - 1]]，即考虑当前数字时，和为 j - nums[i - 1] 的子序列数量。
//因此，状态转移方程为：dp[i][j] = dp[i - 1][j] + (j≥nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0)
//
//3. 初始化
//dp[0][0] = 1：表示考虑前 0 个数字时，和为 0 的子序列有 1 个（即空子序列）。
//dp[0][j] = 0（对于 j > 0）：表示考虑前 0 个数字时，和为 j > 0 的子序列不存在。
//
//4. 填表顺序
//通常，我们按顺序考虑每个数字（i 从 1 到 n），对于每个 i，再考虑所有可能的和 j 从 0 到 target。
//
//5. 返回值
//最终的结果是 dp[n][target]，即考虑所有 n 个数字时，和为 target 的子序列数量。


// 常规二维 DP（内存超限）：
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n = 0;
    cin >> n;

    long long target = 0;
    cin >> target;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[n][target];
    return 0;
}



// 一维 DP 数组优化
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n = 0;
    cin >> n;

    long long target = 0;
    cin >> target;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long> dp(target + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // for (int j = target; j >= v[i - 1]; j--)
        for (int j = target; j >= 0; j--)
        {
            dp[j] = dp[j];
            if (j >= v[i - 1])
            {
                dp[j] = (dp[j] + dp[j - v[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[target];
    return 0;
}