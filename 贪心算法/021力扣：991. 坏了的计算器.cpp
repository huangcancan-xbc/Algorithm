// 力扣：991. 坏了的计算器
// 链接：https://leetcode.cn/problems/broken-calculator/description/

// 方法：正难则反 + 贪心
class Solution
{
public:
    int brokenCalc(int startValue, int target)
    {
        int ret = 0;                            // 记录操作数
        while (target > startValue)             // 如果目标值大于起始值，则需要进行操作
        {
            if (target % 2 == 0)
            {
                target /= 2;                    // 此时如果目标值是偶数，则需要除以2
            }
            else
            {
                target += 1;                    // 此时如果目标值是奇数，则需要加1
            }

            ret++;                              // 记录一次操作
        }

        return ret + startValue - target;       // 此时，数字 startValue 小于或者等于 target，执行 +1 操作的次数：startValue - target，再加上之前的操作次数 ret
    }
};