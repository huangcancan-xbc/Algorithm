//力扣：209. 长度最小的子数组
//https://leetcode.cn/problems/minimum-size-subarray-sum/description/

//滑动窗口的核心思想是：
//维护一段区间（即一段“滑动”的窗口），只在在这个窗口内进行操作，其中，这个窗口的左右边界是指针left和right，
//窗口的大小是right - left + 1。在移动的过程中，窗口的大小不断变化。以达到降低时间复杂度的目的。



//解法一：暴力法
//时间复杂度：O(n^2)，力扣测试用例会超时
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();    // 数组长度
        int minLen = INT_MAX;   // 初始化最小长度为无穷大

        // 遍历所有子数组的起始点 i
        for (int i = 0; i < n; i++) {
            int sum = 0;  // 当前子数组的和从 0 开始

            // 遍历从 i 到 n-1 的每一个可能的子数组终点 j
            for (int j = i; j < n; j++) {
                sum += nums[j];  // 累加子数组的元素

                // 如果子数组和 >= target，则更新最小长度
                if (sum >= target) {
                    minLen = min(minLen, j - i + 1);  // 记录子数组的长度
                    break;  // 一旦找到满足条件的子数组，停止内层循环
                }
            }
        }

        // 如果没有找到符合条件的子数组，返回 0，否则返回最小长度
        return minLen == INT_MAX ? 0 : minLen;
    }
};





//解法二：利用单调性，使用“同向双指针”（滑动窗口）来优化
//单调性-->滑动窗口<--同向不回退
//算法原理：
//1.left=0,right=0
//2.判断
//        -出窗口
//***更新结果***（窗口长度变化多样，具体看题目）

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();   // 获取数组的长度
        int sum = 0;           // 滑动窗口内子数组的当前和
        int len = INT_MAX;     // 初始化最小长度为一个很大的值，代表还没有找到符合条件的子数组，如果开始给0，那么就没有比0小的子数组了

        // 双指针法：左指针(left)和右指针(right)组成滑动窗口
        for (int left = 0, right = 0; right < n; right++) 
        {
            sum += nums[right];                         // 将nums[right]的值加入当前子数组的和

            // 当子数组和大于等于目标值target时，尝试收缩窗口
            while (sum >= target) 
            {
                
                len = min(len, right - left + 1);       // 更新最小长度，如果当前窗口的长度(right - left + 1)更小
                sum -= nums[left++];                    // 将左边的元素移出窗口，并右移左指针，继续尝试缩小窗口
            }
        }

        
        return len == INT_MAX ? 0 : len;                // 如果len未更新，说明没有符合条件的子数组，返回0；否则返回最小长度
    }
};
//算法的正确性：
//
//1.滑动窗口：
//每次移动 right，我们扩大窗口；而当窗口的和满足条件时，我们通过移动 left 来缩小窗口。通过这两个操作，
//算法保证了能够遍历所有可能的子数组，同时尽可能找到满足条件的最短子数组。
//2.同向双指针：
//左指针 left 和右指针 right 同向移动的策略保证了不会遗漏任何可能的子数组，并且在满足条件时尝试最优缩小子数组长度。
//3.时间复杂度：
//每个元素最多被 right 和 left 各遍历一次，因此时间复杂度为 O(n)，其中 n 是数组的长度。这是算法的核心优化点，相比暴力解法 O(n ^ 2) 更高效。


//为什么 len = min(len, right - left + 1); 必须在 sum -= nums[left++]; 之前？
//1.len = min(len, right - left + 1); ：这是更新当前窗口的最小长度的操作。
//当 sum >= target 时，当前的窗口长度为 right - left + 1，此时你要检查当前的子数组是否是到目前为止最短的。
//如果是，就更新 len。这个操作必须在窗口收缩之前完成，因为此时 right - left + 1 是当前窗口的正确长度。
//
//如果你先执行 sum -= nums[left++]; ，你已经把 left 增加了，窗口左边界缩小了，导致你记录的长度变小，会得到错误的窗口长度。
//
//2.sum -= nums[left++]; ：这是用于缩小窗口的操作。你需要在确认当前窗口长度后再缩小窗口的左边界。
//因此，这个操作应该在 len 更新之后进行。
//
//-示例解释
//假设有数组 nums = [2, 3, 1, 2, 4, 3]，目标值 target = 7。
//
//right = 3 时，子数组为[2, 3, 1, 2]，其和为 8，大于目标值 7。此时我们想缩小窗口。
//如果先更新 len：此时窗口长度为 4（right - left + 1），我们更新 len。
//然后缩小窗口：把 left 增加为 1，窗口变为[3, 1, 2]，此时和为 6，不满足 sum >= target，窗口收缩结束。
//如果你把 sum -= nums[left++]; 放在 len = min(len, right - left + 1); 之前，left 会提前增加，
//导致窗口变成[3, 1, 2]，此时窗口长度为 3，但窗口和已经小于目标值 7，错误地更新了 len。