// 力扣：674. 最长连续递增序列
// 链接：https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/

// 方法：贪心 + 双指针
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int ret = 1, n = nums.size();               // 定义结果变量和数组长度

        for (int i = 0; i < n;)                     // 遍历一遍数组
        {
            int j = i + 1;                          // 定义右指针每次从i+1开始
            while (j < n && nums[j] > nums[j - 1])  
            {
                j++;                                // 如果右指针合法并且右指针指向的元素大于左指针指向的元素，则右指针右移
            }

            ret = max(ret, j - i);                  // 更新结果
            i = j;                                  // 不要忘记更新左指针
        }

        return ret;                                 // 返回结果
    }
};