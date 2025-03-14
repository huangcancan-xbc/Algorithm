// 力扣：375. 猜数字大小 II
// 链接：https://leetcode.cn/problems/guess-number-higher-or-lower-ii/description/


//方法一：递归（会超时）
class Solution
{
public:
    int dfs(int left, int right)
    {
        if (left >= right)
        {
            return 0;                       // 如果区间无效（left >= right），直接返回 0
        }

        int ret = INT_MAX;                  // 初始化最小代价为一个很大的值

        for (int head = left; head <= right; head++)
        {
            int x = dfs(left, head - 1);    // 递归计算区间 [left, head-1] 的代价
            int y = dfs(head + 1, right);   // 递归计算区间 [head+1, right] 的代价
            
            // 对于每个数字 head，代价是 head（猜测数字的代价）+ max(x, y)
            // 由于需要考虑最坏的情况，所以我们选择更大的代价
            ret = min(ret, head + max(x, y));
        }

        return ret;                         // 返回当前区间 [left, right] 的最小代价
    }

    int getMoneyAmount(int n)
    {
        return dfs(1, n);                   // 从区间 [1, n] 开始递归
    }
};



//方法二：记忆化搜索
class Solution
{
public:
    int memo[201][201];                     // memo 数组用于存储子问题的计算结果

    int dfs(int left, int right)
    {
        if (memo[left][right] != 0)
        {
            return memo[left][right];       // 如果这个子问题已经计算过了，直接返回结果
        }

        if (left >= right)
        {
            return 0;
        }

        int ret = INT_MAX;

        for (int head = left; head <= right; head++)
        {
            int x = dfs(left, head - 1);
            int y = dfs(head + 1, right);
            ret = min(ret, head + max(x, y));
        }

        memo[left][right] = ret;            // 将当前区间 [left, right] 的最小代价存入 memo 数组，避免重复计算
        return ret;
    }

    int getMoneyAmount(int n)
    {
        return dfs(1, n);
    }
};



//方法三：动态规划
class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));   // dp[i][j] 表示区间 [i, j] 内最小的猜测代价

        // 从较小的区间开始填充 dp 数组
        for (int len = 2; len <= n; ++len)                      // len 是区间的长度
        {
            for (int left = 1; left <= n - len + 1; ++left)
            {
                int right = left + len - 1;                     // 区间的右端点
                dp[left][right] = INT_MAX;

                // 枚举猜测数字 head，并计算代价
                for (int head = left; head <= right; ++head)
                {
                    // 当前猜测数字 head，代价是 head + max(dp[left][head-1], dp[head+1][right])
                    int cost = head + max(
                        head - 1 >= left ? dp[left][head - 1] : 0, // 如果 head - 1 大于等于 left，则计算区间 [left, head-1] 的代价
                        head + 1 <= right ? dp[head + 1][right] : 0 // 如果 head + 1 小于等于 right，则计算区间 [head+1, right] 的代价
                    );

                    dp[left][right] = min(dp[left][right], cost); // 更新最小代价
                }
            }
        }

        return dp[1][n];                                        // 返回区间 [1, n] 的最小代价
    }
};
