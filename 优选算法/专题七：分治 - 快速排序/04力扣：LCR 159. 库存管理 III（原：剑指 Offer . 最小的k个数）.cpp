//力扣：LCR 159. 库存管理 III（原：剑指 Offer . 最小的k个数）
//https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/description/


//方法一：排序
//时间复杂度：O(nlogn)
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) 
    {
        sort(stock.begin(), stock.end());
        return { stock.begin(),stock.begin() + cnt };
    }
};





//方法二：堆排
//时间复杂度：O(nlogk)
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt)
    {
        priority_queue<int> maxHeap;                    // 使用大顶堆来存储最小的cnt个元素

        for (int num : stock)
        {
            maxHeap.push(num);                          // 将当前元素放入堆中
            if (maxHeap.size() > cnt)
            {
                maxHeap.pop();                          // 若堆大小超过cnt，移除最大元素
            }
        }

        vector<int> result(cnt);
        for (int i = cnt - 1; i >= 0; --i)
        {
            result[i] = maxHeap.top();                  // 将堆中元素依次弹出，得到最小的cnt个元素
            maxHeap.pop();
        }
        return result;
    }
};





//方法三：快速选择算法
//时间复杂度：O(n)

//算法原理：
//在快排中，当我们把数组「分成三块」之后：[l, left][left + 1, right - 1][right, r] ，
//我们可以通过计算每⼀个区间内元素的「个数」，进⽽推断出最⼩的 k 个数在哪些区间⾥⾯。
//那么我们可以直接去「相应的区间」继续划分数组即可。
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& nums, int k)
    {
        srand(time(NULL));                               // 设置随机数种子
        qsort(nums, 0, nums.size() - 1, k);        // 调用快速选择算法
        return { nums.begin(), nums.begin() + k };       // 返回最小的k个元素
    }

    // 快速选择算法的递归函数
    void qsort(vector<int>& nums, int left, int right, int k)
    {
        if (left >= right)
        {
            return;
        }

        int key = getrandom(nums, left, right);   // 获取随机基准元素
        int l = left - 1, r = right + 1, i = left;

        while (i < r)
        {
            if (nums[i] < key)
            {
                swap(nums[++l], nums[i++]);              // 将小于基准的元素放到左侧
            }
            else if (nums[i] > key)
            {
                swap(nums[--r], nums[i]);                // 将大于基准的元素放到右侧
            }
            else
            {
                ++i;                                     // 跳过等于基准的元素
            }
        }

        int a = l - left + 1;                     // 左部分元素数量
        int b = r - l - 1;                       // 基准部分元素数量

        if (a >= k)
        {
            qsort(nums, left, l, k);               // 在左部分继续递归
        }
        else if (a + b >= k)
        {
            return;                                      // 若左部分和基准部分元素数量满足k，直接返回
        }
        else
        {
            qsort(nums, r, right, k - a - b);  // 在右部分继续递归
        }
    }

    // 获取随机基准元素
    int getrandom(vector<int>& nums, int left, int right)
    {
        int randomIndex = rand() % (right - left + 1) + left;  // 随机选择索引
        return nums[randomIndex];                              // 返回随机基准值
    }
};