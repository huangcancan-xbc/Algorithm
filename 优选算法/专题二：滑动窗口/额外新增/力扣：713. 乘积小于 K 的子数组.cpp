//力扣：713. 乘积小于 K 的子数组
//https://leetcode.cn/problems/subarray-product-less-than-k/description/


//滑动窗口
//时间复杂度O(n)

//算法原理：
//1. 遍历数组，记录当前窗口内元素的乘积temp。
//2. 如果temp>=k，则说明当前窗口内元素的乘积大于等于k，则缩小窗口，直到temp<k。
//3. 记录当前窗口内符合条件的子数组个数，并移动右指针扩大窗口。
//4. 重复步骤2、3，直到遍历完整个数组。
//5. 返回符合条件的子数组个数。
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        int ret = 0;                    // 结果计数变量, 记录符合条件的子数组数量
        int n = nums.size();            // 数组长度
        int left = 0, right = 0;        // 左、右指针，分别指向滑动窗口的左右边界
        int temp = 1;                   // 当前窗口内元素的乘积

        while (right < n)               // 外层循环遍历数组
        {
            temp *= nums[right];        // 乘上当前右指针元素，扩大窗口

            // 缩小窗口直到乘积小于 k
            while (left <= right && temp >= k)
            {
                temp /= nums[left++];   // 去除左端元素，缩小窗口
            }

            // 当前窗口乘积小于 k，计算符合条件的子数组个数
            if (temp < k)
            {
                ret += right - left + 1;
            }

            right++;                    // 移动右指针扩大窗口
        }

        return ret;
    }
};