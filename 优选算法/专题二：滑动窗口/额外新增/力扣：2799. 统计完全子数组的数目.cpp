// 力扣：2799. 统计完全子数组的数目
// 链接：https://leetcode.cn/problems/count-complete-subarrays-in-an-array/description/

// 方法：哈希表 + 滑动窗口
class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        int n = nums.size();
        unordered_set<int> hash;
        for (int i = 0; i < n; i++)
        {
            hash.insert(nums[i]);               // 用于统计所有元素的种类
        }

        int count = hash.size(), ret = 0, left = 0;
        unordered_map<int, int> map;            // 用于维护窗口中的元素种类

        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;                     // 进窗口
            while (map.size() == count)         // 当窗口中的元素种类等于所有元素种类时，左窗口收缩
            {
                int out = nums[left++];
                if (--map[out] == 0)            // 窗口收缩时，如果元素种类减少为0，则从窗口中删除该元素
                {
                    map.erase(out);
                }
            }

            ret += left;                        // 计算有效的子数组数量
        }

        return ret;
    }
};