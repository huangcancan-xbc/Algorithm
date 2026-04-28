// 力扣：66. 加一
// 链接：https://leetcode.cn/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：数学进位模拟
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            // 题目数据只可能出现10进位
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;  // 中间处理完就返回了
            }

            digits[i] = 0;      // 所以，进完位后一定是0
        }

        digits.insert(digits.begin(), 1);   // 能走到这里说明全是9，需要头插一位
        return digits;
    }
};