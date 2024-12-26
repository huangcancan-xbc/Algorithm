//力扣：215. 数组中的第K个最大元素
//https://leetcode.cn/problems/kth-largest-element-in-an-array/description/


//方法一：库函数sort()，排序后返回第k个元素
//时间复杂度O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ret = nums[n - k];
        return ret;
    }
};




// 方法二：快速选择算法
// 时间复杂度O(n)

// 算法原理：
// 在快排中，当我们把数组「分成三块」之后：[l, left]   [left + 1, right - 1]   [right, r] ，
// 我们可以通过计算每⼀个区间内元素的「个数」，进⽽推断出我们要找的元素是在「哪⼀个区间」⾥⾯。
// 那么我们可以直接去「相应的区间」去寻找最终结果就好了。

// 快速选择是一种基于快速排序的选择算法，平均时间复杂度为 O(n)
// 在快排的分区操作中，将数组划分为三块：[l, left], [left + 1, right - 1], [right, r]
// (通过每个区间的元素数量判断第 k 大元素所在区间，递归查找目标区间直到找到结果)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        srand(time(NULL));                                          // 随机种子，保证随机性
        return qsort(nums, 0, nums.size() - 1, k);            // 递归查找第 k 大元素
    }

    // 快速选择函数，递归查找第 k 大元素
    int qsort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)                                                 // 基本情况：左右边界重合，直接返回该元素
        {
            return nums[l];
        }

        int key = getRandom(nums, l, r);                            // 随机选取一个基准值 key
        int left = l - 1, right = r + 1, i = l;

        // 三指针分区，将数组分为三部分：[l, left], [left + 1, right - 1], [right, r]
        while (i < right)
        {
            if (nums[i] < key)
            {
                swap(nums[++left], nums[i++]);                      // 小于 key 的元素交换到左边
            }
            else if (nums[i] == key)
            {
                i++;                                                // 等于 key 跳过
            }
            else
            {
                swap(nums[--right], nums[i]);                       // 大于 key 的元素交换到右边
            }
        }

        int c = r - right + 1;                             // 右区间元素数量
        int a = right - left - 1;                         // 中间区元素数量

        if (c >= k)
        {
            return qsort(nums, right, r, k);                  // 在右区间递归查找
        }
        else if (a + c >= k)
        {
            return key;                                             // key 即为第 k 大元素
        }
        else
        {
            return qsort(nums, l, left, k - a - c); // 在左区间递归查找
        }
    }

    // 获取随机基准值，减少最坏情况发生概率
    int getRandom(vector<int>& nums, int left, int right)
    {
        return nums[rand() % (right - left + 1) + left];            // 映射随机数到 [left, right] 范围
    }
};