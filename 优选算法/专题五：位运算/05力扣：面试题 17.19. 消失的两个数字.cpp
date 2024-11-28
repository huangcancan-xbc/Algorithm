//力扣：面试题 17.19. 消失的两个数字
//https://leetcode.cn/problems/missing-two-lcci/description/


//方法一：哈希表
//时间复杂度：O(n)
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) 
    {
        int n = nums.size() + 2;                                //原数组应该有 n + 2 个元素
        unordered_set<int> set(nums.begin(), nums.end());       //将现有元素放进哈希表
        vector<int> ret;

        //检查 1 到 n + 2 中缺失的数字
        for (int i = 1; i <= n; i++)
        {
            if (set.find(i) == set.end())
            {
                ret.push_back(i);                               //如果在哈希表中找不到，说明是缺失的数字
            }

            if (ret.size() == 2)                                //找到两个缺失数字即可停止
            {
                break;
            }
        }

        return ret;
    }
};





//方法二：排序比对
//时间复杂度：O(nlogn)
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int> ret;
        sort(nums.begin(), nums.end());                         //先对数组排序

        int cur = 1;                                            //从 1 开始找到缺失的数
        for (auto x : nums)
        {
            while (x != cur)                                    //发现缺失的数字
            {
                ret.push_back(cur);                             //加入到结果
                cur++;                                          //移动到下一个

                if (ret.size() == 2)                            //找到两个缺失数字则退出
                {
                    return ret;
                }
            }

            cur++;
        }

        while (ret.size() < 2)                                  //如果到末尾还有缺失数字
        {
            ret.push_back(cur++);                               //就把剩下的数字都加入到结果
        }

        return ret;
    }
};





//方法二：位运算
//时间复杂度：O(n)
//算法原理：
//本题就是 268. 丢失的数字 + 260. 只出现⼀次的数字 III 组合起来的题。
//先将数组中的数和[1, n + 2] 区间内的所有数「异或」在⼀起，问题就变成了：有两个数出现了「⼀次」，其余所有的数出现了「两次」。
//进⽽变成了 260. 只出现⼀次的数字 III 这道题。
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) 
    {
        int n = nums.size();
        int ret = 0;                                        // 1. 存储所有元素和1到n+2的异或结果

        // 步骤1: 异或 nums 数组中的所有元素
        for (auto x : nums) 
        {
            ret ^= x;
        }

        // 步骤2: 再异或 1 到 n+2 之间的所有整数
        for (int i = 1; i <= n + 2; i++) 
        {
            ret ^= i;
        }
        // 此时 ret 的结果等于 "缺失的两个数字的异或结果"
        
        int diff = 0;                                       // 存储第一个不为0的比特位的位置

        // 步骤3: 找出 ret 中第一个为 1 的比特位，用来区分两个缺失数字
        while (1) 
        {
            if ((ret >> diff) & 1 == 1)                     // 判断 ret 在 diff 位置上的比特位是否为 1
            {  
                break;
            }
            else 
            {
                diff++;                                     // 如果该位是0，继续检查下一位
            }
        }

        // 步骤4: 将元素分组并分别进行异或运算
        int group1 = 0, group2 = 0;

        // 将 nums 中的数按 diff 位是否为 1 分成两组，并分别异或
        for (auto x : nums) 
        {
            if ((x >> diff) & 1 == 1)                       // 第一组：该位为1的数字
            {
                group1 ^= x;  
            }
            else                                            // 第二组：该位为0的数字
            {
                group2 ^= x;  
            }
        }

        // 将 1 到 n+2 中的数按 diff 位是否为 1 分成两组，并分别异或
        for (int i = 1; i <= n + 2; i++) 
        {
            if ((i >> diff) & 1 == 1) 
            {
                group1 ^= i;
            }
            else 
            {
                group2 ^= i;
            }
        }

        // 返回两个缺失的数字
        return { group1, group2 };
    }
};
