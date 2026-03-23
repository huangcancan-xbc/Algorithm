// 力扣：80. 删除有序数组中的重复项 II
// 链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii?envType=study-plan-v2&envId=top-interview-150

// 方法一：双/快慢指针
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;   // 长度小于等于2一定合法
        }

        int left = 2, right = 2;
        while (right < n)
        {
            if (nums[left - 2] != nums[right])
            {
                nums[left] = nums[right];
                left++;
            }

            right++;
        }

        return left;
    }
};


// 方法二：哈希
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        unordered_map<int, int> hash;
        vector<int> ret;
        for (auto x : nums)
        {
            if (hash[x] < 2)    // 出现小于2次就算合法并进行计数
            {
                ret.push_back(x);
                hash[x]++;
            }
        }

        nums = ret;
        return nums.size();
    }
};