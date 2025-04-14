// 力扣：300. 最长递增子序列
// 链接：https://leetcode.cn/problems/longest-increasing-subsequence/description/

// 方法：贪心 + 二分查找
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ret;
        ret.push_back(nums[0]);                         // 以 nums[0] 作为初始递增序列

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ret.back())
            {
                ret.push_back(nums[i]);                 // 当前元素比序列最后一个元素大，直接添加
            }
            else                                        // 需要用二分查找找到第一个 >= nums[i] 的位置，并替换
            {
                int left = 0, right = ret.size() - 1;
                
                while (left < right)
                {
                    int mid = (left + right) >> 1;

                    if (ret[mid] < nums[i])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid;
                    }
                }

                ret[left] = nums[i];                    // 退出循环后，left 指向第一个 >= nums[i] 的位置，进行替换
            }
        }

        return ret.size();                              // 最终 ret 的大小即为最长递增子序列的长度
    }
};