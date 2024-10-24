//力扣：1658. 将 x 减到 0 的最小操作数
//https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/


//方法一：暴力枚举
//时间复杂度：O(n^2)
//暴力解法的关键在于它尝试所有可能的左端和右端组合，并检查移除这些元素之后，剩下的数组是否满足和等于 x。
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();              // 数组长度
        int minOps = INT_MAX;             // 初始化最小操作数为非常大的值

        // 枚举移除左端元素的个数
        for (int left = 0; left <= n; ++left) {
            // 枚举移除右端元素的个数
            for (int right = 0; right <= n - left; ++right) {
                int sum = 0;              //注意，每轮循环都要初始化 sum，使sum = 0,不会影响之前的计算结果

                // 计算左端部分的和
                for (int i = 0; i < left; ++i) {
                    sum += nums[i];
                }

                // 计算右端部分的和
                for (int i = n - right; i < n; ++i) {
                    sum += nums[i];
                }

                // 如果左端+右端的和等于x，则更新最小操作数
                if (sum == x) {
                    minOps = min(minOps, left + right);
                }
            }
        }

        // 如果找到满足条件的组合，返回最小操作数，否则返回 -1
        return minOps == INT_MAX ? -1 : minOps;
    }
};
//外层 for 循环遍历左端移除的元素个数，循环次数是 n + 1 次。
//内层 for 循环遍历右端移除的元素个数，循环次数是 n + 1 次。
//最内层两个循环分别计算左端和右端的和，复杂度为 O(n)。
//因此，总的时间复杂度为 O(n ^ 2)，对于大规模数组的性能会很差。









//方法二：滑动窗口
//时间复杂度：O(n)
//算法原理：
// 题⽬要求的是数组「左端+右端」两段连续的、和为 x 的最短数组，信息量稍微多⼀些，不易理清思路；
// 我们可以转化成求数组内⼀段连续的、和为 sum(nums) - x 的最⻓数组。此时，就是熟悉的「滑动窗⼝」问题了。
// （因为题目中途会进行左右操作，这就会使得常规的方法很难解决，这时就需要正难则反——滑动窗口）


//a.转化问题：求 target = sum(nums) - x 。如果 target < 0 ，问题⽆解；
//b.初始化左右指针 l = 0, r = 0 （滑动窗⼝区间表⽰为[l, r) ，左右区间是否开闭很重要，必须设定与代码⼀致），
//    记录当前滑动窗⼝内数组和的变量 sum = 0 ，记录当前满⾜条件数组的最⼤区间⻓度 maxLen = -1 ；
//c.当 r ⼩于等于数组⻓度时，⼀直循环：
//    i. 如果 sum < target ，右移右指针，直⾄变量和⼤于等于 target ，或右指针已经移到头；
//    ii. 如果 sum > target ，右移左指针，直⾄变量和⼩于等于 target ，或左指针已经移到头；
//    iii. 如果经过前两步的左右移动使得 sum == target ，维护满⾜条件数组的最⼤⻓度，并让下个元素进⼊窗⼝；
//d.循环结束后，如果 maxLen 的值有意义，则计算结果返回；否则，返回 - 1 。


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();         // 获取数组的长度
        int ret = -1;                // 初始化返回值，-1表示如果找不到结果就返回-1
        int sum = 0;                 // 记录整个数组的总和

        // 计算数组中所有元素的总和
        for (int it : nums)
        {
            sum += it;
        }

        int target = sum - x;         // 计算目标值，即子数组的和应该是总和减去x

        // 如果target小于0，表示x大于数组的总和，不可能通过从数组中移除元素得到x
        if (target < 0)
        {
            return -1;                // 返回-1表示无解
        }

        // 使用滑动窗口寻找和为target的最长子数组
        for (int left = 0, right = 0, temp = 0; right < n; right++)
        {
            temp += nums[right];      // 累加窗口内元素的和

            // 当窗口内的和大于target时，移动左边界，缩小窗口
            while (target < temp)
            {
                temp -= nums[left++]; // 减去左边界元素的值，并将左边界右移
            }

            // 当窗口内的和等于target时，更新结果
            if (target == temp)       //target <= temp也可以，因为存在子数组相加，前一个数小于target，再加一个数就存在大于等于target了
            {
                // ret记录最长子数组的长度，right - left + 1为当前子数组长度
                ret = max(ret, right - left + 1);
            }
        }

        // 如果ret未更新，说明没有找到和为target的子数组，返回-1
        if (ret == -1)
        {
            return -1;
        }
        else
        {
            // 返回结果为总长度减去最长子数组的长度，即移除的元素个数
            return n - ret;
        }
    }
};
