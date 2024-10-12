//力扣：283. 移动零
//https://leetcode.cn/problems/move-zeroes/description/

//算法原理：
//属于数组划分/数组分块类问题
//使用双指针算法-->利用数组下标充当指针

//两个指针的作用：
//1. cur指针：从左往右扫描数组，遍历数组
//2. dest指针：已经处理的区间内，非零元素的最后一个位置

//三个区间：
//[0, dest]     [dest + 1, cur - 1]     [cur, n - 1]
//   非0                0                  待处理

//如何做到：
//cur从前往后遍历的过程中：
//1.遇到0元素，cur++
//2.遇到非0元素
//      a. swap(nums[dest + 1], nums[cur])
//      b. dest++, cur++


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
        {
            // 判断当前元素是否为非零元素
            if (nums[cur])
            {
                // swap: 交换nums[dest + 1]和nums[cur]的值
                // 目的：将非零元素移到前面，零元素留在后面
                swap(nums[++dest], nums[cur]);
            }
        }
    }
};