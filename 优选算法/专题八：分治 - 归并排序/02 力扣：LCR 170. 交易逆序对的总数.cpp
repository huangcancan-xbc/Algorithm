// 力扣：LCR 170. 交易逆序对的总数
// 链接：https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/

// 算法原理：
//逆序对定义：若下标 i < j 且 record[i] > record[j]，则(i, j) 是一个逆序对。
//
//最直接的方法就是两重循环：时间复杂度：O(n²) → 太慢，力扣会超时！
//int count = 0;
//for (int i = 0; i < n; ++i)
//    for (int j = i + 1; j < n; ++j)
//        if (record[i] > record[j]) ++count;
//
//利用“分治 + 排序”的过程中顺便统计逆序对：
//1. 把数组分成两个子区间：record[left ~mid] 和 record[mid + 1 ~right]
//2. 递归分别统计两个子区间的逆序对数量；
//3. 关键：在合并两个有序子数组时，统计“跨区间的逆序对”
//
//在归并的过程中，左右两个子数组已经各自是有序的。我们只要在合并这两段时：
//    当发现 record[cur1] > record[cur2]，并且：cur1 属于左边，cur2 属于右边
//    那么就可以直接算出：record[cur1] 比右边的 cur2 ~right 所有数都大！
//    其逆序对数量是 right - cur2 + 1

// 方法：归并排序 + 逆序对计数
class Solution
{
public:
    int temp[50010];                                    // 临时数组（避免频繁动态申请）

    int mergesort(vector<int>& record, int left, int right)
    {
        if (left >= right)
        {
            return 0;                                   // 递归终止条件：一个元素，无逆序对
        }

        int mid = (left + right) / 2;                   // int mid = (left + right) >> 1;也可以
        int ret = 0;                                    // 当前区间内的逆序对计数

        // 递归处理左右两个子区间
        ret += mergesort(record, left, mid);            // 统计左半部分逆序对
        ret += mergesort(record, mid + 1, right);       // 统计右半部分逆序对

        // 下面进行归并 + 统计「跨左右两边」的逆序对
        int cur1 = left, cur2 = mid + 1, i = 0;         // 左右两个子区间的指针，i 指向 temp 数组

        while (cur1 <= mid && cur2 <= right)            // 合并左右有序子数组的同时统计逆序对
        {
            if (record[cur1] <= record[cur2])
            {
                temp[i++] = record[cur1++];             // 若左 <= 右，说明无逆序对，直接加入 temp
            }
            else
            {
                // 若左 > 右，说明从 cur1 到 mid 都大于 record[cur2]，因此从产生 (mid - cur1 + 1) 个逆序对
                ret += mid - cur1 + 1;
                temp[i++] = record[cur2++];
            }
        }

        // 剩余元素依次加入 temp（归并排序的常规步骤）
        while (cur1 <= mid)
        {
            temp[i++] = record[cur1++];
        }
        while (cur2 <= right)
        {
            temp[i++] = record[cur2++];
        }

        // 把排好序的 temp 区间复制回原数组对应位置
        for (int i = left; i <= right; i++)
        {
            record[i] = temp[i - left];
        }

        return ret;                                     // 返回当前区间的逆序对个数
    }

    int reversePairs(vector<int>& record)
    {
        return mergesort(record, 0, record.size() - 1);
    }
};





// 方法：归并排序按“降序归并”思路实现
class Solution
{
public:
    int temp[50010];                                    // 临时数组，用于归并排序

    // mergesort 函数：返回 [left, right] 区间的逆序对个数
    int mergesort(vector<int>& record, int left, int right)
    {
        if (left >= right)
        {
            return 0;                                   // 单个元素无逆序对
        }

        int mid = (left + right) / 2;
        int ret = 0;                                    // 当前区间逆序对数量

        // 递归分治左右子数组
        ret += mergesort(record, left, mid);
        ret += mergesort(record, mid + 1, right);

        // 下面进行归并 + 统计「跨左右两边」的逆序对
        int cur1 = left, cur2 = mid + 1, i = 0;         // 左右两个子区间的指针，i 指向 temp 数组

        while (cur1 <= mid && cur2 <= right)            // 归并过程，同时统计逆序对
        {
            if (record[cur1] <= record[cur2])           // 若左 <= 右，说明无逆序对
            {
                temp[i++] = record[cur2++];             // 注意这里优先取右边（降序归并）
            }
            else                                        // 若左 > 右，说明左侧 record[cur1]，对右边 cur2~right 所有元素都形成逆序对
            {
                ret += right - cur2 + 1;                // 累加逆序对数量
                temp[i++] = record[cur1++];             // 仍然按降序归并方向
            }
        }

        // 拷贝剩余元素
        while (cur1 <= mid)
        {
            temp[i++] = record[cur1++];
        }
        while (cur2 <= right)
        {
            temp[i++] = record[cur2++];
        }

        
        for (int i = left; i <= right; i++)
        {
            record[i] = temp[i - left];                 // 将排序结果拷贝回原数组
        }

        return ret;                                     // 返回该段区间的逆序对数量
    }

    int reversePairs(vector<int>& record)
    {
        return mergesort(record, 0, record.size() - 1);
    }
};