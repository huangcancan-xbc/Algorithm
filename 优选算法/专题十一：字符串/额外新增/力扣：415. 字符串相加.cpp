// 力扣：415. 字符串相加
// 链接：https://leetcode.cn/problems/add-strings/description/

// 方法：字符串、模拟
// 方法：模拟加法竖式计算，需要考虑进位、反转和边界问题
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int prev = 0;   // （往前的）进位数字
        string ret = "";

        // 从后往前加，只要没加完或者进位不为0就一直继续
        while (i >= 0 || j >= 0 || prev > 0)
        {
            // 越界当0使
            int val1 = i >= 0 ? num1[i] - '0' : 0;
            int val2 = j >= 0 ? num2[j] - '0' : 0;

            int val = val1 + val2 + prev;   // 当前2数和
            ret += (val % 10 + '0');        // 添加到结果
            prev = val / 10;                // 更新进位的数

            i--;
            j--;
        }

        reverse(ret.begin(), ret.end());    // 反转

        return ret;
    }
};