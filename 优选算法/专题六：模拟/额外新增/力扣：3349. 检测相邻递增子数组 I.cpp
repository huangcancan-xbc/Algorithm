//力扣：3349. 检测相邻递增子数组 I
//https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-i/description/


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k)
        {
            return false;
        }

        for (int i = 0; i <= n - 2 * k; i++)
        {
            int nums1 = true, nums2 = true;             // 记录 nums[i:i+k-1] 和 nums[i+k:i+2*k-1] 是否严格递增

            for (int j = i; j < i + k - 1; j++)
            {
                if (nums[j] >= nums[j + 1])
                {
                    nums1 = false;
                    break;
                }
            }

            for (int j = i + k; j < i + 2 * k - 1; j++)// 注意：这里是 i+k 而不是 i+k-1
            {
                if (nums[j] >= nums[j + 1])
                {
                    nums2 = false;
                    break;
                }
            }

            if (nums1 && nums2)
            {
                return true;
            }
        }

        return false;
    }
};





class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        int n = nums.size();

        if (n < 2 * k)
        {
            return false;                       // 如果数组长度小于 2*k，直接返回 false
        }

        for (int i = 0; i <= n - 2 * k; i++)
        {
            bool firstIncreasing = true;        // 检查从 i 开始的长度为 k 的子数组是否严格递增

            for (int j = 1; j < k; j++)
            {
                if (nums[i + j] <= nums[i + j - 1])
                {
                    firstIncreasing = false;    // 如果有不递增的情况，标记为 false
                    break;
                }
            }

            if (!firstIncreasing)
            {
                continue;                       // 如果第一个子数组不是递增的，跳过当前循环，检查下一个起始位置
            }

            // 检查从 i + k 开始的长度为 k 的子数组是否严格递增
            bool secondIncreasing = true;

            for (int j = 1; j < k; j++)
            {
                if (nums[i + k + j] <= nums[i + k + j - 1])
                {
                    secondIncreasing = false;    // 如果有不递增的情况，标记为 false
                    break;
                }
            }

            if (secondIncreasing)
            {
                return true;                    // 如果两个子数组都严格递增，返回 true
            }
        }

        return false;                           // 如果没有找到符合条件的子数组，返回 false
    }
};