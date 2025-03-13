// 力扣：300. 最长递增子序列
// 链接：https://leetcode.cn/problems/longest-increasing-subsequence/description/



//方法一：递归（会超时）
class Solution
{
public:
    int n;

    int dfs(int pos, vector<int>& nums)
    {
        int ret = 1;                                // 最短的 LIS 以当前元素为结尾

        for (int i = pos + 1; i < n; i++)           // 遍历当前元素之后的所有元素
        {
            if (nums[i] > nums[pos])                // 如果有元素比当前元素大
            {
                ret = max(ret, dfs(i, nums) + 1);   // 递归求解
            }
        }

        return ret;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        n = nums.size();
        int ret = 0;

        for (int i = 0; i < n; i++)                 // 对每个位置调用 dfs
        {
            ret = max(ret, dfs(i, nums));           // 取最大值
        }

        return ret;
    }
};




//方法二：记忆化搜素
class Solution
{
public:
    int n;

    int dfs(int pos, vector<int>& nums, vector<int>& memo)
    {
        if (memo[pos] != 0)
        {
            return memo[pos];                       // 如果已经计算过，直接返回
        }

        int ret = 1;                                // 最短的 LIS 以当前元素为结尾

        // 遍历当前元素之后的所有元素
        for (int i = pos + 1; i < n; i++)
        {
            if (nums[i] > nums[pos])                // 如果有元素比当前元素大
            {
                ret = max(ret, dfs(i, nums, memo) + 1);  // 递归求解
            }
        }

        memo[pos] = ret;                            // 保存计算结果
        return ret;
    }

    int lengthOfLIS(vector<int>& nums)
    {
        n = nums.size();
        int ret = 0;

        vector<int> memo(n, 0);                     // 初始化 memo 数组为 0

        for (int i = 0; i < n; i++)                 // 对每个位置调用 dfs
        {
            ret = max(ret, dfs(i, nums, memo));     // 取最大值
        }

        return ret;
    }
};



//方法三：动态规划
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);                       // 初始化 dp 数组，最短的 LIS 长度为 1
        int ret = 0;                                // 最终答案

        // 从后向前遍历每个元素
        for (int i = n - 1; i >= 0; i--)
        {
            // 遍历当前元素之后的所有元素
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])              // 如果有元素比当前元素大
                {
                    dp[i] = max(dp[i], dp[j] + 1);  // 更新 dp[i] 值
                }
            }
            ret = max(ret, dp[i]);                  // 更新答案
        }

        return ret;
    }
};
