//力扣：217. 存在重复元素
//链接：https://leetcode.cn/problems/contains-duplicate/description/


//方法：哈希表
//时间复杂度：O(n)
//空间复杂度：O(n)

//算法原理：
//分析⼀下题⽬，出现「⾄少两次」的意思就是数组中存在着重复的元素，因此我们可以⽆需统计元素出现的数⽬。仅需在遍历数组的过程中，检查当前元素「是否在之前已经出现过」即可。
//因此我们可以利⽤哈希表，仅需存储数「组内的元素」。在遍历数组的时候，⼀边检查哈希表中是否已经出现过当前元素，⼀边将元素加⼊到 哈希表中。
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> hash;            // 定义一个哈希表

        for (auto x : nums)
        {
            if (hash.count(x))              // 如果哈希表中存在当前元素，说明存在重复元素
            {
                return true;                // 返回 true
            }
            else
            {
                hash.insert(x);             // 否则，插入到哈希表中
            }
        }

        return false;
    }
};