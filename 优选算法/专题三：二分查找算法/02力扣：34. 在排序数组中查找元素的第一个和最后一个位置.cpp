//力扣：34. 在排序数组中查找元素的第一个和最后一个位置
//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/


//方法一：暴力法
//时间复杂度O(n)

//通过遍历整个数组，检查每个元素是否等于目标值。
//一旦找到目标值，记录第一次出现的位置（begin）和最后一次出现的位置（end）。
//如果整个数组遍历结束后没有找到目标值，返回{ -1, -1 }。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = -1, end = -1;         // 存储第一个和最后一个位置
        bool found = false;               // 标记是否找到目标

        // 遍历数组
        for (int left = 0; left < nums.size(); left++) 
        {
            if (nums[left] == target) 
            {   // 找到目标
                if (!found)               // 第一次找到时
                {             
                    begin = left;         // 记录第一个位置
                    found = true;         // 标记已找到
                }
                end = left;               // 更新最后一个位置
            }
        }

        // 如果未找到目标或数组为空
        if (!found || nums.size() == 0) 
        {
            return { -1, -1 };            // 返回 {-1, -1}
        }
        else 
        {
            return { begin, end };        // 返回第一个和最后一个位置
        }
    }
};






//方法二：二分查找
//时间复杂度O(logn)
//算法原理：
//1.首先进行边界检查，如果数组为空，直接返回{ -1, -1 }。
//2.查找第一个位置：
//    i.使用二分查找的思想，定义两个指针 left 和 right，初始化为数组的两端。
//    ii.在 left 小于 right 的情况下，计算中间索引 mid。
//    iii.如果 nums[mid] 小于目标值，则目标在右侧，移动 left；否则，移动 right，确保找到最左侧的目标值。
//3.查找最后一个位置：
//    重置 left 和 right，再次使用二分查找，但这次调整逻辑以确保找到最右侧的目标值。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return { -1, -1 };          // 数组为空，返回 {-1, -1}
        }

        // 二分查找第一个位置
        int begin = 0;
        int left = 0, right = nums.size() - 1;

        while (left < right) 
        {
            int mid = left + (right - left) / 2;   // 计算中间索引
            if (nums[mid] < target)                // 中间元素小于目标
            {              
                left = mid + 1;                    // 左指针右移
            }
            else 
            {
                right = mid;                       // 右指针移到中间
            }
        }

        if (nums[left] != target)                  // 如果目标不在最后位置
        {                
            return { -1, -1 };                     // 返回 {-1, -1}
        }
        else 
        {
            begin = left;                          // 记录第一个位置
        }

        // 二分查找最后一个位置
        left = 0, right = nums.size() - 1;

        while (left < right) 
        {
            int mid = left + (right - left + 1) / 2;  // 计算中间索引，偏向右侧
            if (nums[mid] <= target)                  // 中间元素小于等于目标
            {                
                left = mid;                           // 左指针移到中间
            }
            else 
            {
                right = mid - 1;                      // 右指针移到中间 - 1
            }
        }

        return { begin, right };                      // 返回第一个和最后一个位置
    }
};
