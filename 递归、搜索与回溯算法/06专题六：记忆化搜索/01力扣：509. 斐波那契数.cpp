// 力扣：509. 斐波那契数
// 链接：https://leetcode.cn/problems/fibonacci-number/description/


//方法一：递归
class Solution
{
public:
    int dfs(int n)
    {
        // 基本情况：斐波那契数列的第 0 和第 1 项分别为 0 和 1
        if (n == 0 || n == 1)
        {
            return n;                       // 返回 n，即返回斐波那契数列的前两项
        }

        return dfs(n - 1) + dfs(n - 2);     // 递归计算第 n 个斐波那契数，通过递归调用计算 f(n-1) 和 f(n-2)
    }

    int fib(int n)
    {
        return dfs(n);                      // 调用递归函数来计算结果
    }
};



//方法二：记忆化搜索
class Solution
{
public:
    int memo[31];                           // 用于存储计算过的斐波那契数结果

    int dfs(int n)
    {
        if (memo[n] != -1)
        {
            return memo[n];                 // 如果 memo[n] 不为 -1，说明该结果已经计算过，直接返回
        }

        // 基本情况：斐波那契数列的第 0 和第 1 项分别为 0 和 1
        if (n == 0 || n == 1)
        {
            memo[n] = n;                    // 记录结果
            return n;
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);  // 递归计算并将结果存入 memo （计算 f(n) = f(n-1) + f(n-2)）
        return memo[n];                     // 返回结果
    }

    int fib(int n)
    {
        memset(memo, -1, sizeof memo);      // 初始化 memo 数组，设置所有值为 -1（表示未计算）
        return dfs(n);                      // 调用递归函数来计算结果
    }
};



//方法三：动态规划
class Solution
{
public:
    int dp[31];                             // 用于存储每个斐波那契数的结果

    int fib(int n)
    {
        dp[0] = 0;                          // f(0) = 0
        dp[1] = 1;                          // f(1) = 1

        // 从 f(2) 开始计算，直到 f(n)
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];  // 动态规划转移方程：f(n) = f(n-1) + f(n-2)
        }

        return dp[n];                       // 返回 f(n)
    }
};
