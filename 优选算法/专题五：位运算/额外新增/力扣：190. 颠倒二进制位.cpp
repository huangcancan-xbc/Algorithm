// 力扣：190. 颠倒二进制位
// 链接：https://leetcode.cn/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：位运算 + 数学 + 字符串
// 思路：
// 1. 将 n 转化为二进制字符串，并补齐前导 0，使其长度为 32
// 2. 遍历字符串，从右到左，将每个字符转化为数字，并左移 cnt 位，累加到 ret 中
// 3. 返回 ret
class Solution
{
public:
    int reverseBits(int n)
    {
        string s;
        // 必须循环32次，保证补齐前导0
        for (int i = 0; i < 32; ++i)
        {
            s += (n % 2) + '0'; // 先取余，并转为字符
            n /= 2;
        }

        long ret = 0, cnt = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            // 字符转数字需减 '0'，用移位代替 pow
            ret += (s[i] - '0') * (1L << cnt++);
        }

        return ret;
    }
};