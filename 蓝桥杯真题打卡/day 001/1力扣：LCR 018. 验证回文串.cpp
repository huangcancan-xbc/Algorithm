//力扣：LCR 018. 验证回文串
//链接：https://leetcode.cn/problems/XltzEq/description/


//方法：字符串处理
class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        string ss;

        // 过滤非字母数字字符
        for (auto x : s)
        {
            if (x >= 'a' && x <= 'z')
            {
                ss += x;
            }
            if (x >= 'A' && x <= 'Z')
            {
                ss += tolower(x);
            }
            if (x >= '0' && x <= '9')
            {
                ss += x;
            }
        }

        string tmp(ss.rbegin(), ss.rend());         // 反转字符串
        return tmp == ss;                           // 判断是否回文
    }
};



class Solution 
{
public:
    bool isPalindrome(string s)
    {
        string ss;

        // 过滤非字母数字字符
        for (auto x : s)
        {
            if (isalnum(x))
            {
                ss += tolower(x);
            }
        }

        string tmp(ss.rbegin(), ss.rend());         // 反转字符串
        return tmp == ss;                           // 判断是否回文
    }
};