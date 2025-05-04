// 力扣：912. 排序数组
// 链接：https://leetcode.cn/problems/sort-an-array/description/

// 方法：归并排序
class Solution
{
public:
    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;                                     // 递归终止条件：区间内只有一个元素
        }

        int mid = (left + right) / 2;                   // 取中间位置（也可以写成 >>1）

        // 递归排序左半部分和右半部分
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        vector<int> temp(right - left + 1);             // 合并两个有序子数组，临时数组，用于合并排序结果

        int cur1 = left;                                // 左指针，指向左半部分的起始位置
        int cur2 = mid + 1;                             // 右指针，指向右半部分的起始位置
        int i = 0;                                      // temp 数组的下标

        while (cur1 <= mid && cur2 <= right)            // 双指针合并排序
        {
            temp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];     // 每次选择较小的值放入 temp，并移动对应指针
        }

        while (cur1 <= mid)
        {
            temp[i++] = nums[cur1++];                   // 若左半部分还有剩余，全部拷贝到 temp
        }
        while (cur2 <= right)
        {
            temp[i++] = nums[cur2++];                   // 若右半部分还有剩余，全部拷贝到 temp
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];                   // 将合并后的结果拷贝回原数组对应位置
        }
    }

    vector<int> sortArray(vector<int>& nums)
    {
        mergesort(nums, 0, nums.size() - 1);            // 对整个数组进行归并排序
        return nums;
    }
};



// 优化：使用全局变量
class Solution
{
public:
    vector<int> temp;                                   // 临时数组作为类成员，避免每次递归都创建新数组

    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        int mid = (left + right) / 2;
        // int mid = (left + right) >> 1; // 等价于上一行

        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            temp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];
        }

        while (cur1 <= mid)
        {
            temp[i++] = nums[cur1++];                   // 处理剩余左侧部分
        }
        while (cur2 <= right)
        {
            temp[i++] = nums[cur2++];                   // 处理剩余右侧部分
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }

    }

    vector<int> sortArray(vector<int>& nums)
    {
        temp.resize(nums.size());                       // 初始化临时数组大小（只分配一次）
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};