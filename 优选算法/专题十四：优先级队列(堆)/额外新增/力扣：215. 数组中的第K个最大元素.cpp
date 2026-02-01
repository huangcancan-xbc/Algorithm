// 力扣：215. 数组中的第K个最大元素
// 链接：https://leetcode.cn/problems/kth-largest-element-in-an-array/description/

// 方法一：堆
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> q(nums.begin(), nums.end());
        while (--k) // 后置--会多弹出一个值，导致错误！
        {
            q.pop();
        }

        return q.top();
    }
};



// 方法二：快排
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        return nums[k - 1];
    }
};

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};