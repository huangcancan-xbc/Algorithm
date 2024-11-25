//力扣：268. 丢失的数字
//https://leetcode.cn/problems/missing-number/description/


//方法一：哈希表
//时间复杂度：O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n + 1, 0);         // 初始化计数数组，大小为 n+1

        for (auto x : nums)
        {
            hash[x] = 1;                    // 标记每个出现的数字
        }

        for (int i = 0; i <= n; i++)
        {
            if (hash[i] == 0)
            {
                return i;                   // 返回没有出现的数字
            }
        }

        return -1;                          // 逻辑上不应该到达这里

    }
};




//方法二：高斯求和
//时间复杂度：O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();                    // 数组大小
        int sum = n * (n + 1) / 2;              // 计算0到n的和
        int ret = 0;
        for (auto x : nums)                     // 计算数组中出现的数字的和
        {
            ret += x;
        }

        ret = sum - ret;                        //理论 - 实际 = 缺失的数字
        return ret;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;      // 0 到 n 的和
        int actualSum = 0;                      // 数组中实际的和

        for (int num : nums) 
        {
            actualSum += num;                   // 计算数组中的总和
        }

        return expectedSum - actualSum;         // 返回缺失的数字
    }
};





//方法三：位运算
//时间复杂度：O(n)

//算法原理：
//设数组的⼤⼩为 n ，那么缺失之前的数就是[0, n] ，数组中是在[0, n] 中缺失⼀个数形成的序列。
//如果我们把数组中的所有数，以及[0, n] 中的所有数全部「异或」在⼀起，那么根据「异或」运算的「消消乐」规律，最终的异或结果应该就是缺失的数~
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int ret = 0;

        for (int i = 0; i < n; i++)                 // 将所有 nums 数组的元素进行异或
        {
            ret ^= nums[i];
        }

        for (int i = 0; i <= n; i++)                // 将 0 到 n 的所有数字进行异或
        {
            ret ^= i;
        }

       
        return ret;                                 // 最终 ret 为缺失的数字
    }
};
