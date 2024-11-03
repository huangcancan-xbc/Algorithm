//力扣：852. 山脉数组的峰顶索引
//https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/


// 方法一：暴力法
//时间复杂度：O(n)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int ret = 0;                    // 初始化返回值
        // 遍历数组，寻找峰顶索引
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                ret = i;                // 找到峰顶，更新返回值
                break;                  // 找到第一个峰顶后退出循环
            }
        }

        return ret;                     // 返回峰顶索引
    }
};






//方法二：二分查找
//时间复杂度：O(logn)

//算法原理：
//峰顶的特点：⽐两侧的元素都要⼤。
//因此，我们可以遍历数组内的每⼀个元素，找到某⼀个元素⽐两边的元素⼤即可。
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        //边界最左和最右的元素一定不是峰顶，可以简单优化
        int left = 1;                   // 左指针从1开始，避免越界
        int right = arr.size() - 2;     // 右指针从倒数第二个元素开始

        // 当左指针小于右指针时，进行二分查找
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;  // 计算中间位置，偏向右边

            if (arr[mid] > arr[mid - 1])
            {
                left = mid;             // mid是上升部分，更新左指针
            }
            else
            {
                right = mid - 1;        // mid是下降部分，更新右指针
            }
        }

        return left;                    // 返回峰顶索引
    }
};