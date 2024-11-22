//力扣：260. 只出现一次的数字 III
//https://leetcode.cn/problems/single-number-iii/description/


//方法一：哈希表
//时间复杂度：O(n)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        // 1. 统计每个数字的出现次数
        for (auto x : nums)
        {
            mp[x]++;
        }

        vector<int> ans;

        // 2. 遍历哈希表，找到出现次数为 1 的数字
        for (auto x : mp)
        {
            if (x.second == 1)
            {
                ans.push_back(x.first);             // 使用 x.first，表示该数字
            }
        }

        return ans;                                 // 返回只出现一次的两个元素
    }
};





//方法二：位运算
//时间复杂度：O(n)
//算法原理：
//1. 计算所有数字的异或结果
//2. 找到两个数字之间的第一个不同的比特位
//3. 按第一个不同的比特位分组，并异或运算
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all = 0;

        // 1. 计算所有数字的异或 (XOR) 结果
        //    通过 XOR 操作，成对的相同数字会被抵消，最终 all 存储的是两个只出现一次的数字的异或结果
        for (auto x : nums) 
        {
            all ^= x;
        }

        // 2. 找到第一个不同的比特位 (bit)
        //    这个比特位表示这两个数字在此位置的值不同
        int diff = 1;
        while ((all & diff) == 0) 
        {
            diff <<= 1;                         // 左移一位，直到找到 all 中第一个为 1 的比特位
        }

        // 3. 根据第一个不同的比特位，将数字分成两组并分别进行异或运算
        //    分组依据：该比特位是 1 的放入 group1，是 0 的放入 group2
        int group1 = 0, group2 = 0;
        for (auto x : nums) 
        {
            if ((x & diff) != 0) 
            {
                group1 ^= x;                    // 第一个组：比特位为 1
            }
            else 
            {
                group2 ^= x;                    // 第二个组：比特位为 0
            }
        }

        // 4. 返回两个只出现一次的数字
        return { group1, group2 };
    }
};
