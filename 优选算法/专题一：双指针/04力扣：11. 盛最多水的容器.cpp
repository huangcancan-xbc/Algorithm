//力扣：11. 盛最多水的容器
//https://leetcode.cn/problems/container-with-most-water/description/

//暴力枚举，时间复杂度O(n^2)
//注意：此段代码只是一种解法，实际时间复杂度较高，无法通过力扣的测试用例。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        // 遍历所有可能的两个柱子组合
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                // 计算高度和宽度
                int temp = min(height[i], height[j]) * (j - i);
                // 更新最大面积
                ret = max(ret, temp);
            }
        }

        return ret;
    }
};





//利用单调性，使用双指针来解决问题。时间复杂度O(n)
//算法原理：

//设定两个指针，left和right，分别指向数组的左右两端。
//每次移动指针，使得left和right之间的距离尽可能小，直到left和right重合。
//在移动指针的过程中，计算当前的面积，并与ret进行比较，更新ret。
//如果height[left] < height[right]，则left右移；否则right左移。
//直到left和right重合，返回ret。

class Solution {
public:
    // 计算能够容纳的最大水量
    int maxArea(vector<int>& height) {
        int left = 0;                        // 初始化左指针，指向数组的开始
        int right = height.size() - 1;      // 初始化右指针，指向数组的结束
        int ret = 0;                         // 用于存储最大水量

        // 当左指针小于右指针时，继续计算
        while (left < right)
        {
            // 计算当前的水量，取两边较小的高度，乘以宽度
            int v = min(height[left], height[right]) * (right - left);
            ret = max(ret, v);               // 更新最大水量ret

            // 移动指针：选择较小的高度，尝试找到更大的水量
            if (height[left] < height[right])
            {
                left++;                      // 左指针右移
            }
            else
            {
                right--;                     // 右指针左移
            }
        }

        return ret;                          // 返回找到的最大水量
    }
};
