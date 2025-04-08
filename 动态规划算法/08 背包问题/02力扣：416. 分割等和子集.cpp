// 力扣：416. 分割等和子集
// 链接：https://leetcode.cn/problems/partition-equal-subset-sum/description/

// 方法：动态规划
class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size(), sum = 0;

        for (int x : nums)
        {
            sum += x;                       // 计算数组总和
        }
        if (sum % 2 == 1)
        {
            return false;                   // 如果总和为奇数，则无法分割成两个相等的子集
        }

        int target = sum / 2;               // 目标子集和，总和是定值，取一半则另一半自然相等
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;                // 初始化：当子集和为 0 时，总能满足（不选任何元素）
        }

        // 逐步填充 DP 数组
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                dp[i][j] = dp[i - 1][j];    // 不选择当前元素的情况

                // 选择当前元素的情况（前提：j >= nums[i-1]）
                if (j >= nums[i - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];               // 目标是否可达
    }
};



// 优化：
class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int n = nums.size(), sum = 0;
        for (auto x : nums)
        {
            sum += x;
        }
        if (sum % 2 == 1)
        {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = target; j >= nums[i - 1]; j--)
            {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }
};