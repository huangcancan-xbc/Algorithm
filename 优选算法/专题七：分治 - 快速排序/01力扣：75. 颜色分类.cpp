//力扣：75. 颜色分类
//https://leetcode.cn/problems/sort-colors/description/


//方法一：库函数sort()
//时间复杂度：O(nlogn)
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
    }
};




//方法二：三指针法
//时间复杂度：O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = -1, i = 0, right = nums.size();
        while (i < right)
        {
            if (nums[i] == 0)
            {
                swap(nums[++left], nums[i++]);
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[--right], nums[i]);
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int left = -1;                                  // 指向 0 最右边的位置
        int i = 0;                                      // 遍历数组的当前元素位置
        int right = nums.size();                        // 指向 2 最左边的位置

        while (i < right)                               // 遍历数组，直到指针 i 到达 right 位置
        {
            if (nums[i] == 0)
            {
                swap(nums[++left], nums[i++]);          // 把 0 交换到左边，并移动 i
            }
            else if (nums[i] == 1)
            {
                i++;                                    // 如果是 1，直接移动 i，不做交换
            }
            else
            {
                swap(nums[--right], nums[i]);           // 把 2 交换到右边，i 保持不变，检查交换回来的数
            }
        }
    }
};
//使用三指针法（也称为双指针法改进版）。
//设置三个指针：
//    指针一：left：用于记录 0 的位置区域的右边界。
//    指针二：right：用于记录 2 的位置区域的左边界。
//    指针三：i：遍历数组的当前位置。
//通过三指针的配合操作，可以在一次遍历中完成排序，实现线性时间复杂度