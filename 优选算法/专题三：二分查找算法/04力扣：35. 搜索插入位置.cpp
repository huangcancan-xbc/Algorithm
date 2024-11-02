//力扣：35. 搜索插入位置
//https://leetcode.cn/problems/search-insert-position/description/


// 方法一：暴力法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // 遍历数组，找到目标值位置或比目标值大的第一个位置
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;                // 找到目标值，返回索引
            }
            else if (nums[i] > target)
            {
                return i;                // 找到比目标值大的位置，返回该索引
            }
        }

        return nums.size();              // 若目标值比所有元素都大，返回数组长度
    }
};






// 方法二：二分查找法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;                    // 左指针初始化
        int right = nums.size() - 1;     // 右指针初始化

        // 二分查找，直到左右指针重合
        while (left < right)
        {
            int mid = left + (right - left) / 2;  // 计算中间位置，避免溢出
            if (nums[mid] < target)
            {
                left = mid + 1;         // 目标值在右半部分，移动左指针
            }
            else
            {
                right = mid;            // 目标值在左半部分，或等于中间值，移动右指针
            }
        }

        // 判断目标值的插入位置
        if (nums[left] < target)
        {
            return left + 1;            // 目标值大于当前元素，应插入到下一个位置
        }

        return left;                    // 目标值应插入当前位置
    }
};
