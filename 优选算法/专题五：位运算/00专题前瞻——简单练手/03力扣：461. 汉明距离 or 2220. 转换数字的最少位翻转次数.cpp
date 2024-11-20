//力扣：461. 汉明距离 or 2220. 转换数字的最少位翻转次数
//https://leetcode.cn/problems/hamming-distance/description/
//https://leetcode.cn/problems/minimum-bit-flips-to-convert-number/description/


//方法一：内置函数
// 使用 XOR（异或）运算获取 x 和 y 不同的位
// 使用 __builtin_popcount() 内置函数来统计1的个数（即不同位的数量）
class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};




//方法二：位运算
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y;                      // 计算不同位：使用 XOR 得到 s，s 的二进制表示中，1 表示不同位
        int ret = 0;

        // 遍历每一位，计算 s 中的1的数量
        for (int i = 0; i < 32; i++) 
        {
            ret += (s >> i) & 1;            // 右移 i 位并与 1 进行按位与运算，检查第 i 位是否为1
        }

        return ret;
    }
};