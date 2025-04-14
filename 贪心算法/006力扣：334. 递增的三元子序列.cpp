// 力扣：334. 递增的三元子序列
// 链接：https://leetcode.cn/problems/increasing-triplet-subsequence/description/

// 方法：贪心算法
class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int a = nums[0], b = INT_MAX;           // a 记录当前最小的数，b 记录当前次小的数，初始化为无穷大

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > b)                    // 如果找到了比 b 还大的数，说明找到了递增三元组
            {
                return true;
            }
            else if (nums[i] > a)               // 如果 nums[i] 介于 a 和 b 之间，更新 b
            {
                b = nums[i];
            }
            else                                // 如果 nums[i] 比当前的最小值 a 还小，更新 a
            {
                a = nums[i];
            }
        }

        return false;                           // 遍历结束后仍未找到满足条件的三元组
    }
};