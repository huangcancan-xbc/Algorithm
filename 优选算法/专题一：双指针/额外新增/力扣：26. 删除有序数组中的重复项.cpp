// 力扣：26. 删除有序数组中的重复项
// 链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array?envType=study-plan-v2&envId=top-interview-150

// 方法：双指针
// 注意题目不是简单的去重！而是要对原始数组做操作
// 定2个指针，初始0和1，当这2个指针的值相等时，右指针右移
// 如果值不相等，左指针先后移，避免覆盖有效数据，然后将右指针的值赋值给左指针，右指针右移
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int left = 0, right = 1;
        while (right < nums.size())
        {
            if (nums[left] == nums[right])
            {
                right++;
            }
            else
            {
                left++;     // 先后移
                nums[left] = nums[right++];
            }
        }

        return left + 1;    // left是最终的下标，返回个数应该是下标 +1
    }
};