// 力扣：1005. K 次取反后最大化的数组和
// 链接：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/

// 方法：贪心（数学）
class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        int count = 0, minElem = INT_MAX, ret = 0;               // 记录负数的数量，记录数组中的最小绝对值元素，记录最终的数组和

        for (auto x : nums)                                      // 遍历数组，统计负数数量，并找到最小绝对值元素
        {
            if (x < 0)
            {
                count++;                                         // 统计负数个数
            }

            minElem = min(minElem, abs(x));                      // 更新最小绝对值元素
        }

        // 情况 1：负数数量大于 k，优先翻转前 k 个最小的负数
        if (count > k)
        {
            sort(nums.begin(), nums.end());                      // 先对数组排序，让负数排在前面

            // 翻转前 k 个负数
            for (int i = 0; i < k; i++)
            {
                ret += -nums[i];                                 // 取反并加入总和
            }

            // 其余元素直接加入总和
            for (int i = k; i < nums.size(); i++)
            {
                ret += nums[i];
            }
        }
        else
        {
            // 情况 2：负数数量小于等于 k，先翻转所有负数
            for (auto x : nums)
            {
                ret += abs(x);                                   // 负数翻转后变成正数，正数保持不变
            }

            // 如果剩余操作 k - count 仍是奇数，需要翻转最小的正数或 0
            if ((k - count) % 2)
            {
                ret -= minElem * 2;                              // 再次翻转最小的元素，使总和最大
            }
        }

        return ret;                                              // 返回最终的最大和
    }
};


class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        // 1. 排序，使负数靠前
        sort(nums.begin(), nums.end());

        // 2. 贪心翻转负数
        for (int i = 0; i < nums.size() && k > 0 && nums[i] < 0; i++, k--)
        {
            nums[i] = -nums[i];                         // 翻转负数
        }

        // 3. 计算当前数组和
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 4. 若剩余 k 为奇数，需要再翻转最小的正数
        if (k % 2 == 1)
        {
            sum -= 2 * (*min_element(nums.begin(), nums.end()));
        }

        return sum;
    }
};
