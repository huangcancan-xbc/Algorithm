//力扣：704. 二分查找
//https://leetcode.cn/problems/binary-search/description/


//方法一：暴力法
//时间复杂度O(n)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 遍历数组 nums，查找目标值 target
        for (int left = 0; left < nums.size(); left++) 
        {
            if (nums[left] == target) 
            {
                return left;                       // 找到目标值，返回索引
            }
        }

        return -1;                                 // 未找到目标值，返回-1
    }
};






//方法二：二分查找
//时间复杂度O(logn)
// 
//算法原理：
//1.初始化左右边界 left 和 right，分别指向数组的起始和结束位置。
//2.计算中间索引 mid，并比较 nums[mid] 与 target 的大小关系。
//3.根据比较结果，决定是向左还是向右收缩查找范围：
//    i.如果 nums[mid] < target，则目标值在右半部分，更新 left。
//    ii.如果 nums[mid] > target，则目标值在左半部分，更新 right。
//    iii.如果相等，返回当前的 mid。
//4.如果循环结束后仍未找到目标值，返回 - 1。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;  // 初始化左右边界

        // 当左边界小于等于右边界时，继续查找
        while (left <= right) 
        {
            int mid = (left + right) / 2;       // 计算中间索引

            // 如果中间值小于目标值，缩小查找范围到右半部分
            if (nums[mid] < target) 
            {
                left = mid + 1;                 // 更新左边界
            }
            // 如果中间值大于目标值，缩小查找范围到左半部分
            else if (nums[mid] > target) 
            {
                right = mid - 1;                // 更新右边界
            }
            // 如果中间值等于目标值，返回该索引
            else 
            {
                return mid;                     // 找到目标值，返回索引
            }
        }

        return -1;                              // 未找到目标值，返回-1
    }
};
