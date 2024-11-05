// 力扣：153. 寻找旋转排序数组中的最小值
// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

// 方法一：暴力法
// 时间复杂度：O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size() - 1;    // 获取数组的最后一个索引
        int ans = nums[0];          // 初始化答案为第一个元素

        for (int i = 1; i <= n; i++)
        {
            if (nums[i] < ans)      // 如果当前元素小于答案
            {
                ans = nums[i];      // 更新答案为当前元素
            }
        }

        return ans;                 // 返回找到的最小值
    }
};





// 方法二：二分查找
// 时间复杂度：O(log n)

// 算法原理：
//当数组旋转之后，会变成两段递增的数组：一段在左边，一段在右边。 此时需要通过“二段性”进行分类讨论：
//    如果数组最后一个元素大于中间元素，则最小值在右半部分。
//    如果数组最后一个元素小于中间元素，则最小值在左半部分。
//    如果数组最后一个元素等于中间元素，则不能直接确定最小值的位置，需进一步搜索。

//具体步骤：
//1.设定左右指针，左指针指向数组第一个元素，右指针指向数组最后一个元素。
//2.设定一个变量 x，记录右端的值（即 nums[right]）。
//3.循环条件：左指针小于右指针。
//4.计算中间索引：mid = left + (right - left) / 2（使用这种方式避免溢出）。
//5.如果中间元素大于右端值，则最小值在右半部分，更新左指针为 mid + 1。
//6.如果中间元素小于等于右端值，则最小值在左半部分，更新右指针为 mid。
//7.循环结束，返回左指针所指向的元素，即最小值。

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;                           // 左指针
        int right = nums.size() - 1;            // 右指针
        int x = nums[right];                    // 记录右端的值

        while (left < right)
        {
            int mid = left + (right - left) / 2;// 计算中间索引

            if (nums[mid] > x)                  // 如果中间元素大于右端值
            {
                left = mid + 1;                 // 最小值在右半部分
            }
            else
            {
                right = mid;                    // 最小值在左半部分
            }
        }

        return nums[left];                      // 返回左指针所指向的元素
    }
};
