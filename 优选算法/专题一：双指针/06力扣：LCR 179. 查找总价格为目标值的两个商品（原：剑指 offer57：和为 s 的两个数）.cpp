//力扣：LCR 179. 查找总价格为目标值的两个商品（原：剑指 offer57：和为 s 的两个数）
//https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
//注意：两个方法都使用到了列表初始化和C++的返回类型推导的特性，可自行学习这个知识点，提高编程能力。
//同时，我放了一个配套的图片，帮助理解使用列表初始化和C++的返回类型推导的特性。



// 暴力枚举策略：
// 时间复杂度O(n^2)，最简单的方法，但会超时
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int n = price.size(); // 获取数组的长度

        // 枚举两个数的组合
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // 判断两个数之和是否等于目标值
                if (price[i] + price[j] == target) {
                    return { price[i], price[j] }; // 找到两个数，直接返回
                }
            }
        }

        // 如果没有找到，返回{-1,-1}表示无解
        return { -1, -1 };
    }
};





//算法原理：利用单调性，使用双指针算法解决问题
//时间复杂度O(n)
//因为数组是单调递增的，所以利用数组的单调性，指针left指向数组的第一个元素，指针right指向数组的最后一个元素
//用sum存贮两个数的和，如果sum小于target，则left右移，如果sum大于target，则right左移，如果sum等于target，则返回两个数
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0;                           // 左指针指向第一个元素
        int right = price.size() - 1;           // 右指针指向最后一个元素
        int sum = 0;                            // 存储两个数的和

        // 当左指针小于右指针时继续循环
        while (left < right) 
        {
            sum = price[left] + price[right];   // 计算两个数的和

            if (sum < target) 
            {
                left++; // 和小于目标值，右移左指针，增大和
            }
            else if (sum > target) 
            {
                right--; // 和大于目标值，左移右指针，减小和
            }
            else 
            {
                // 找到符合条件的两个数，直接返回
                return { price[left], price[right] };
            }
        }

        // 如果没有找到符合条件的数，返回{-1,-1}
        return { -1, -1 };
    }
};
