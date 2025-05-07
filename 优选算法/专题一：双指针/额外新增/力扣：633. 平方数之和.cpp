// 力投：633. 平方数之和
// 链接：https://leetcode.cn/problems/sum-of-square-numbers/description/

// 方法：双指针（左右指针）
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long long left = 0, right = sqrt(c);            // 左指针从 0 开始，右指针从 sqrt(c) 开始

        while (left <= right)                           // 当 left 小于 right 时，进行遍历
        {
            long long sum = left * left + right * right;// 计算当前左右指针平方和

            if (sum == c)                               // 如果和等于 c，说明找到一对 (left, right)，返回 true
            {
                return true;
            }
            else if (sum < c)
            {
                left++;                                 // 如果当前和小于 c，表示需要增大左指针
            }
            else
            {
                right--;                                // 如果当前和大于 c，表示需要减小右指针
            }
        }

        return false;                                   // 如果不存在满足条件的对，返回 false
    }
};