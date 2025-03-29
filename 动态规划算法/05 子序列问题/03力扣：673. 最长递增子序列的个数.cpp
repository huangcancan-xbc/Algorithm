// 力扣：673. 最长递增子序列的个数
// 链接：https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();                    // 获取数组长度

        // len[i] 表示以 nums[i] 为结尾的最长递增子序列的长度，count[i] 表示以 nums[i] 为结尾的最长递增子序列的个数
        vector<int> len(n, 1), count(n, 1);
        int retlen = 1, retcount = 1;           // retlen 表示最长递增子序列的长度，retcount 表示其出现的个数

        for (int i = 1; i < n; i++)             // 遍历数组的每个元素
        {
            for (int j = 0; j < i; j++)         // 对于每个 i，遍历其之前的元素 j
            {
                if (nums[j] < nums[i])          // 如果 nums[j] 小于 nums[i]，说明可以将 nums[i] 加入以 nums[j] 为结尾的递增子序列
                {
                    // 如果以 nums[j] 为结尾的子序列长度 + 1 等于以 nums[i] 为结尾的子序列长度，那么说明找到了一个新的最长递增子序列，更新 count[i]
                    if (len[j] + 1 == len[i])
                    {
                        count[i] += count[j];   // 加上以 nums[j] 结尾的子序列的个数
                    }
                    // 如果以 nums[j] 为结尾的子序列长度 + 1 大于 nums[i] 为结尾的子序列长度，则更新 len[i] 为 len[j] + 1，count[i] 也更新为 count[j]
                    else if (len[j] + 1 > len[i])
                    {
                        len[i] = len[j] + 1;    // 更新最长递增子序列的长度
                        count[i] = count[j];    // 更新以 nums[i] 为结尾的子序列的个数
                    }
                }
            }

            // 更新最终的最长递增子序列的长度和个数
            if (retlen == len[i])
            {
                retcount += count[i];           // 如果当前子序列的长度等于最长长度，累加个数
            }
            else if (retlen < len[i])
            {
                retlen = len[i];                // 更新最长递增子序列的长度
                retcount = count[i];            // 更新最长递增子序列的个数
            }
        }

        return retcount;                        // 返回最终的最长递增子序列的个数
    }
};