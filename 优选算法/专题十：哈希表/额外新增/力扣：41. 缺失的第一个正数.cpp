// 力扣：41. 缺失的第一个正数
// 链接：https://leetcode.cn/problems/first-missing-positive/description/

// 方法一：哈希暴力
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 1;
        }

        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                hash[nums[i]] = 1;
            }
        }

        int index = 1;
        while (index <= nums.size())
        {
            if (hash[index] == 0)
            {
                return index;
            }

            index++;
        }

        return index;
    }
};



// 方法二：用数组下标错位映射值
class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // 注意这里用while一直换到满意为止，以及错位映射
            // 0号下标放1，1号下标放2，……
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;   // 注意错位找缺失数
            }
        }

        return n + 1;
    }
};