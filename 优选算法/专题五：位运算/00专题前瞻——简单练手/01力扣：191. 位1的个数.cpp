//力扣：191. 位1的个数
//https://leetcode.cn/problems/number-of-1-bits/description/


class Solution {
public:
    int hammingWeight(int n) 
    {
        int ret = 0;                    // 计数器，用于记录 1 的个数

        // 遍历 n 的每一位
        for (int i = 0; i < 32; i++) 
        {
            // 检查第 i 位是否为 1
            if ((n >> i) & 1) 
            {
                ret++;                  // 如果是 1，计数器加 1
            }
        }

        return ret;
    }
};