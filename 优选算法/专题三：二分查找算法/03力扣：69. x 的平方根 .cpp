//力扣：69. x 的平方根 
//https://leetcode.cn/problems/sqrtx/description/

//方法一：暴力法：
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)                          // 对于 0 和 1，直接返回
        {
            return x;
        }

        for (long long i = 1; i <= x; i++)  // 从 1 开始线性查找
        {  
            if (i * i > x)                  // 找到第一个 i，使得 i^2 > x
            {  
                return i - 1;               // 返回 i - 1
            }
        }

        return x;                           // 处理 x 为 0 的情况
    }
};






//方法二：牛顿迭代法
//属于数学方法，不要求掌握
class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)                  // 对于 0 和 1，直接返回
        {
            return x;
        }

        double r = x;               // 初始值设为 x
        while (r * r > x)           // 迭代直到 r 的平方小于等于 x
        {
            r = (r + x / r) / 2;    // 更新 r 的值
        }

        return (int)r;              // 返回结果
    }
};






//方法三：二分查找

//算法原理：
//二分查找算法通过不断缩小查找范围，最终找到的 left 就是小于或等于 x 的最大整数的平方根。
//这里的逻辑是将每次的 mid 值与 x 的平方进行比较，以此决定调整左边界还是右边界。
class Solution {
public:
    int mySqrt(int x) {
        if (x < 1)                              // 对于 0，返回 0
        {
            return 0;
        }

        int left = 1, right = x;                // 定义左右边界
        while (left < right)                    // 当左右边界未重合时继续
        {
            long long mid = left + (right - left + 1) / 2;  // 计算中间值，避免溢出
            if (mid * mid > x)                  // 若 mid 的平方大于 x
            {
                right = mid - 1;                // 收缩右边界
            }
            else
            {
                left = mid;                     // 移动左边界
            }
        }

        return left;                            // 返回最终的左边界
    }
};
