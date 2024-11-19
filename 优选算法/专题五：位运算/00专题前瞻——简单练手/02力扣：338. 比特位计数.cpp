//力扣：338. 比特位计数
//https://leetcode.cn/problems/counting-bits/description/


class Solution {
public:
    // 辅助函数：计算整数 n 中的 1 的个数（即汉明重量）
    int countOnes(int n) {
        int ret = 0;                            // 计数器，记录 1 的个数

        // 遍历 n 的每一位
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1)                   // 检查第 i 位是否为 1
            {
                ret++;
            }
        }

        return ret;
    }

    // 主函数：计算 [0, n] 范围内每个数的比特位计数
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);                 // 定义结果数组 ans，大小为 n+1，存储每个数的比特位计数

        // 对每个整数 i 计算其 1 的个数
        for (int i = 0; i <= n; i++) 
        {
            ans[i] = countOnes(i);              // 调用辅助函数 countOnes 计算每个 i 的 1 的个数
        }

        return ans;
    }
};