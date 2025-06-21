// 力扣：2825. 循环增长使字符串子序列等于另一个字符串
// 链接：https://leetcode.cn/problems/make-string-a-subsequence-using-cyclic-increments/description/

// 方法：双指针
class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        if (str1.size() < str2.size())
        {
            return false;                       // 特判
        }

        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size())
        {
            if (str1[i] == str2[j])             // 直接匹配成功
            {
                i++;
                j++;
            }
            else if ((str1[i] - 'a' + 1) % 26 + 'a' == str2[j])     // 循环递增一次后匹配成功
            {
                i++;
                j++;
            }
            else                                // 匹配失败
            {
                i++;
            }
        }

        return j == str2.size();                // 如果 j 达到 str2 的末尾，说明匹配非常成功，返回 true
    }
};