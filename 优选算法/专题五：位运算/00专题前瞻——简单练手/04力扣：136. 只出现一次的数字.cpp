//力扣：136. 只出现一次的数字
//https://leetcode.cn/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;

        // 使用位运算 XOR（异或）来找到只出现一次的数字
        for (auto x : nums) 
        {
            ret ^= x; 
            
            // 每个元素与ret进行异或运算，相同数字异或会抵消 (例如：a ^ a = 0)
            // 因此所有成对出现的数字会被抵消，剩下单个数字
        }

        return ret;
    }
};