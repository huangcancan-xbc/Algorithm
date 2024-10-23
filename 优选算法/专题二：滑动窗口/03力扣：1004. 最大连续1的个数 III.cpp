//力扣：1004. 最大连续1的个数 III
//https://leetcode.cn/problems/max-consecutive-ones-iii/description/


//方法一：暴力法，暴力枚举+zero计数器
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;                    // 记录最大连续1的个数
        int n = nums.size();            // 数组长度

        for (int i = 0; i < n; i++)     // 从第i个位置开始枚举子数组
        {
            int zero_count = 0;         // 计数器，记录当前子数组中0的个数

            for (int j = i; j < n; j++) // 枚举以i开头的子数组
            {
                if (nums[j] == 0)       // 如果遇到0，增加计数器
                {
                    zero_count++;
                }

                if (zero_count > k)     // 如果0的个数超过k，跳出循环
                {
                    break;
                }

                // 更新最大连续1的个数
                ret = max(ret, j - i + 1);
            }
        }

        return ret;                     // 返回最长的连续1的个数
    }
};






//方法二：利用规律，使用“滑动窗口”来解决问题。
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;                     // 记录最大连续1的个数
        int n = nums.size();             // 数组长度
        int zero_count = 0;              // 记录窗口内0的个数

        for (int left = 0, right = 0; right < n; right++) // 右指针不断扩展窗口
        {
            if (nums[right] == 0)        // 如果右指针遇到0，增加0的计数器
            {
                zero_count++;
            }

            // 当窗口内0的个数超过k，移动左指针缩小窗口，直到满足条件
            while (zero_count > k)
            {
                if (nums[left++] == 0)   // 如果左指针遇到0，减少0的计数器
                {
                    zero_count--;
                }
            }

            // 每次更新最大连续1的个数
            ret = max(ret, right - left + 1);
        }

        return ret;                      // 返回最长的连续1的个数
    }
};
//如何理解“滑动窗口”？（同时，这也是滑动窗口的正确性）
//想象一下，现在有一个果冻/皮筋/肥虫，可自由拉伸，将他放到应该数轴上，此时果冻/皮筋/肥虫就像一个窗口，窗口的头和尾分别是左右指针，窗口的宽度就是窗口内元素的个数。
//在这道题目中，我们要始终维护这个窗口，使得窗口内的0的个数不超过k。一旦超过k，我们便缩小窗口/踢出元素，使得窗口内的0的个数恢复正常。
//因此，我们可以用两个指针left和right，分别指向窗口的左右两端，然后不断移动right指针，直到窗口内的0的个数超过k。此时，我们便移动left指针，缩小窗口，直到窗口内的0的个数恢复正常。