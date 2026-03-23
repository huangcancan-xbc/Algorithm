// 力扣：169. 多数元素
// 链接：https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：哈希
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        int n = nums.size();

        for (auto x : nums)
        {
            hash[x]++;
            if (hash[x] > n / 2)
            {
                return x;
            }
        }

        return 0;
    }
};



// 方法二：排序
// 思路：要的结果出现次数是数组的一半还多，那么这个这个数经过排序一定在数组中间的区间中
// 从极端情况来说：排完序，及时这个数是0号位置的数，他的数量过半还多，那么一定会在 size/2 处出现
class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};