//力扣：912. 排序数组
//https://leetcode.cn/problems/sort-an-array/description/


//方法一：库函数sort()
//时间复杂度：O(nlogn)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<int> ret(nums.begin(), nums.end());
        return ret;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());        // 使用库函数 sort() 对数组进行排序
        return nums;                           // 返回排序后的数组
    }
};





//方法二：快排思想 - 三指针法使数组分三块
// 快速排序是基于分治法的排序算法，平均时间复杂度为 O(nlogn)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        srand(time(NULL));                          // 使用当前时间设置随机种子，确保随机性
        qsort(nums, 0, nums.size() - 1);            // 调用快速排序函数对整个数组进行排序
        return nums;                                // 返回排序后的数组
    }

    // 快速排序函数，递归分区排序
    void qsort(vector<int>& nums, int l, int r)
    {
        if (l >= r)                                 // 基本情况：当左边界不小于右边界时，终止递归
        {
            return;
        }

        int key = getRandom(nums, l, r);            // 通过随机函数选取基准值 key
        int i = l, left = l - 1, right = r + 1;

        // 三指针法分区，将数组划分为三部分：[l, left], [left+1, right-1], [right, r]
        while (i < right)
        {
            if (nums[i] < key)
            {
                swap(nums[++left], nums[i++]);      // 将小于 key 的元素移到左侧区域
            }
            else if (nums[i] == key)
            {
                i++;                                // 如果等于 key，直接移动指针
            }
            else
            {
                swap(nums[--right], nums[i]);       // 将大于 key 的元素移到右侧区域
            }
        }

        qsort(nums, l, left);                       // 递归排序左侧区域
        qsort(nums, right, r);                      // 递归排序右侧区域
    }

    // 获取随机基准值，确保快排随机性，减少最坏情况发生的概率
    int getRandom(vector<int>& nums, int left, int right)
    {
        int r = rand();                             // 生成随机数
        return nums[r % (right - left + 1) + left]; // 将随机数映射到指定区间内
    }
};