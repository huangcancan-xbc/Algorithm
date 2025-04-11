// 力扣：279. 完全平方数
// 链接：https://leetcode.cn/problems/perfect-squares/description/

// 方法：完全背包（动态规划）
class Solution
{
public:
    int numSquares(int n)
    {
        int m = sqrt(n);                            // 计算不超过 n 的最大整数平方根，即完全平方数的个数

        // 定义 dp 数组，dp[i][j] 表示使用前 i 个完全平方数凑成 j 需要的最少数量
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // 初始化：当 j>0 且未使用任何完全平方数时，设为一个较大的值，表示无法组成
        for (int i = 1; i <= n; i++)
        {
            dp[0][i] = 0x3f3f3f3f;                  // 取较大的初始值（无穷大）
        }

        // 递推计算 dp 数组
        for (int i = 1; i <= m; i++)                // 遍历完全平方数 i^2
        {
            for (int j = 0; j <= n; j++)            // 遍历目标数 j
            {
                dp[i][j] = dp[i - 1][j];            // 不选择 i^2，则 dp[i][j] = dp[i-1][j]

                if (j >= i * i)                     // 只有当 j 足够大时，才能选择 i^2
                {
                    // 状态转移方程：选择 i^2，则 dp[i][j] = dp[i][j - i*i] + 1
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
                }
            }
        }

        return dp[m][n];                            // 返回最少需要的完全平方数个数
    }
};


// 空间优化：
class Solution
{
public:
    int numSquares(int n)
    {
        int m = sqrt(n);
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0x3f3f3f3f;
        }
        /*或者：
        vector<int> dp(n + 1, 0x3f3f3f3f);
        dp[0] = 0;*/

        for (int i = 1; i <= m; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }
};