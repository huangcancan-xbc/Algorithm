// 力扣：9. 回文数
// 链接：https://leetcode.cn/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：字符串
class Solution
{
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        if (s[0] == '-' || s[0] == '+')
        {
            return false;
        }

        string ss = s;
        reverse(ss.begin(), ss.end());

        return ss == s;
    }
};