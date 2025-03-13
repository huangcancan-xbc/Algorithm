// 力扣：62. 不同路径
// 链接：https://leetcode.cn/problems/unique-paths/description/


//方法一：递归（会超时）
class Solution
{
public:
    int dfs(int i, int j)
    {
        if (i == 0 || j == 0)
        {
            return 0;                           // 边界条件：如果到达第一行或第一列，只有一种路径，到达第一行或第一列时无法再向下走或向右走
        }

        if (i == 1 && j == 1)
        {
            return 1;                           // 基础条件：到达 (1, 1) 时只有一种路径，起始位置到目标位置只有一种路径
        }

        
        return dfs(i - 1, j) + dfs(i, j - 1);   // 递归计算从上方和左方到达当前位置的路径数
    }

    int uniquePaths(int m, int n)
    {
        return dfs(m - 1, n - 1);               // 从目标位置开始计算路径数
    }
};



//方法二：记忆化搜素
class Solution
{
public:
    int dfs(int i, int j, vector<vector<int>>& memo)
    {
        if (memo[i][j] != 0)
        {
            return memo[i][j];                  // 如果已经计算过该位置的路径数，则直接返回
        }

        if (i == 0 || j == 0)
        {
            return 0;                           // 边界条件：如果到达第一行或第一列，只有一种路径，到达第一行或第一列时无法再向下走或向右走
        }

        if (i == 1 && j == 1)
        {
            memo[i][j] = 1;                     // 基础条件：到达 (1, 1) 时只有一种路径，起始位置到目标位置只有一种路径
            return 1;
        }

        memo[i][j] = dfs(i - 1, j, memo) + dfs(i, j - 1, memo); // 递归计算路径数
        return memo[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1));    // 初始化 memo 数组，大小为 m+1 行 n+1 列，初始值为 0

        return dfs(m, n, memo);
    }
};


// 将 memo 数组作为全局变量避免传递参数，提高效率（索引从 0 开始）
class Solution
{
public:
    vector<vector<int>> memo;

    int dfs(int i, int j)
    {
        if (memo[i][j] != 0)
        {
            return memo[i][j];      // 如果已经计算过该位置的路径数，则直接返回
        }

        if (i == 0 || j == 0)
        {
            return 1;               // 边界条件：如果到达第一行或第一列，只能有一种路径，即从左上角走到右下角只有一种方式走到边界
        }

        memo[i][j] = dfs(i - 1, j) + dfs(i, j - 1);     // 递归计算路径数

        return memo[i][j];
    }

    int uniquePaths(int m, int n)
    {
        memo.resize(m, vector<int>(n, 0));              // 初始化 memo 数组，大小为 m 行 n 列，初始值为 0
        return dfs(m - 1, n - 1);                       // 从 (m-1, n-1) 开始（因为数组索引从 0 开始）递归
    }
};


//索引从 1 开始，减少判断边界条件的次数
class Solution
{
public:
    vector<vector<int>> memo;

    int dfs(int i, int j)
    {
        if (memo[i][j] != 0)
        {
            return memo[i][j];      // 如果已经计算过该位置的路径数，则直接返回
        }

        if (i == 1 || j == 1)
        {
            return 1;               // 边界条件：如果到达第一行或第一列，只能有一种路径，即从左上角走到右下角只有一种方式走到边界
        }

        memo[i][j] = dfs(i - 1, j) + dfs(i, j - 1);     // 递归计算路径数

        return memo[i][j];
    }

    int uniquePaths(int m, int n)
    {
        // 初始化 memo 数组，大小为 (m+1) x (n+1)，表示从索引 1 到 m 和 1 到 n
        memo.resize(m + 1, vector<int>(n + 1, 0));      // m+1 行，n+1 列，初始值为 0
        return dfs(m, n);                               // 从 (m, n) 开始递归（因为数组索引从 1 开始）
    }
};


//方法三：动态规划
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[1][1] = 1;                                   // 起始位置到目标位置只有一种路径

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1)
                {
                    continue;                           // 跳过起始位置
                }

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 递推公式
            }
        }

        return dp[m][n];
    }
};