//力扣：1. 两数之和
//链接：https://leetcode.cn/problems/two-sum/description/


//方法一：暴力法
//时间复杂度：O(n^2)
//空间复杂度：O(1)
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)                 // 固定当前数字 nums[i]
            {
                if (nums[i] + nums[j] == target)        // 检查 nums[i] 和 nums[j] 是否满足两数之和等于 target
                {
                    return { i,j };
                }
            }
        }

        return {};
    }
};



//方法二：哈希表
//时间复杂度：O(n)
//空间复杂度：O(n)

//算法原理：
//• 如果我们可以事先将「数组内的元素」和「下标」绑定在⼀起存⼊「哈希表」中，然后直接在哈希表中查找每⼀个元素的 target - nums[i] ，就能快速的找到「⽬标和的下标」。
//• 这⾥有⼀个⼩技巧，我们可以不⽤将元素全部放⼊到哈希表之后，再来⼆次遍历（因为要处理元素相同的情况）。⽽是在将元素放⼊到哈希表中的「同时」，
//  直接来检查表中是否已经存在当前元素所对应的⽬标元素（即 target - nums[i] ）。如果它存在，那我们已经找到了对应解，并⽴即将其返回。⽆需将元素全部放⼊哈希表中，提⾼效率。
//• 因为哈希表中查找元素的时间复杂度是 O(1) ，遍历⼀遍数组的时间复杂度为 O(N) ，因此可以将时间复杂度降到 O(N) 。

//这是⼀个典型的「⽤空间交换时间」的⽅式。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)           // 遍历数组 nums
        {
            hash[nums[i]] = i;                          // 将当前数字和索引丢入哈希表
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];

            // 如果哈希表中存在差值 x 且索引不等于 i，注意：如果差值x=4（nums[i]=4）,nums有4，则需要特判，哈希表中不能存在和差值一样的数字
            if (hash.count(x) && hash[x] != i)
            {
                return { hash[x],i };
            }
        }

        return { -1,-1 };
    }
};



//更加优化的哈希表：
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hash;                   // 哈希表
        for (int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];                   // 计算差值 x
            if (hash.count(x))                          // 如果哈希表中存在差值 x
            {
                return { hash[x],i };                   // 返回索引
            }

            hash[nums[i]] = i;                          // 将当前数字和索引丢入哈希表
        }

        return { -1,-1 };                               // 照顾编译器，防止未定义行为
    }
};
