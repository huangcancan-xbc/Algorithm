//力扣：611. 有效三角形的个数
//https://leetcode.cn/problems/valid-triangle-number/description/

//解法一：暴力枚举法
//枚举三角形的两条边，然后判断是否满足条件
//时间复杂度O(n^3)，提供简单的思路，但无法通过力扣测试

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();    // 获取数组的大小
        int ret = 0;            // 用于记录符合条件的三角形个数

        // 三重循环枚举所有可能的三条边
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // 判断三边是否可以组成三角形
                    // 条件：任意两边之和大于第三边
                    if (nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[i] + nums[k] > nums[j])
                    {
                        ret++;  // 如果满足条件，三角形个数+1
                    }
                }
            }
        }

        return ret;  
    }
};




//解法二：利用单调性，使用双指针算法来解题
//算法原理：
//1.排完序，固定最大的数
//2.在最大数的左区间内，使用双指针算法，快速统计出符合要求的三元组的个数

//巧妙：
//1.a+b>c->right-left,right--
//2.a+b<=c,left++
//解释：
//当C已经最大了，左边的数都小于C，如果最左边的数加C前一个数大于C，说明从最左边的数到C前一个数都可以组成三角形，right-left计数
//如果最左边的数加C前一个数小于C，说明最左边的数和C前一个数不可能组成三角形，开始left++
//存在C左边的数任意两个数之和都小于C，说明没有三角形可以组成，改变最大数C，即for循环使最大数变小，继续判断


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 先排序，方便使用双指针

        int ret = 0, n = nums.size() - 1;

        for (int i = n; i >= 2; i--)  // 固定最大边 nums[i]
        {
            int left = 0, right = i - 1;  // 双指针初始位置：最左和次大边

            while (left < right)
            {
                // 如果最小的两边之和大于最大边，说明能组成三角形
                if (nums[left] + nums[right] > nums[i])
                {
                    ret += right - left;  // 符合条件的三元组个数：从 left 到 right 全部可行
                    right--;  // 右指针左移，寻找新的组合
                }
                else
                {
                    left++;  // 如果两边之和不大于最大边，增大左边，尝试新的组合
                }
            }
        }

        return ret;  // 返回符合条件的三角形个数
    }
};