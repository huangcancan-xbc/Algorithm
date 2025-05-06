//力扣：5. 最长回文子串
//链接：https://leetcode.cn/problems/longest-palindromic-substring/description/


//方法一：暴力法
//时间复杂度：O(n^3)

//两个均只能过样例，提交会超时，仅提供思路参考
class Solution 
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int len = 0;
        string ret;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n - i; j++)
            {
                string sub = s.substr(j, i);
                string tmp(sub.rbegin(), sub.rend());
                if (sub == tmp && i > len)
                {
                    len = i;
                    ret = sub;
                }
            }
        }

        return ret;
    }
}; 

class Solution 
{
public:
    string longestPalindrome(string s)
    {
        int len = 0;
        string ret;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                string ss = s.substr(i, j - i + 1);
                string tmp(ss.rbegin(), ss.rend());
                if (ss == tmp)
                {
                    if (len < j - i + 1)
                    {
                        len = j - i + 1;
                        ret = ss;
                    }
                }
            }
        }

        return ret;
    }
};




//方法二：中心扩展法（双指针）
class Solution 
{
public:
    void dp(const string& s, int left, int right, int& begin, int& maxlen)
    {
        //当循环退出时：
        //    left 已经超出了回文的左边界（比实际边界小 1）。
        //    right 已经超出了回文的右边界（比实际边界大 1）。
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        int len = right - left - 1;     // -1 是为了修正左右边界的多余偏移
        if (maxlen < len)
        {
            maxlen = len;
            begin = left + 1;           // +1 是为了修正左右边界的多余偏移
        }
    }

    string longestPalindrome(string s)
    {
        int begin = 0, maxlen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            dp(s, i, i, begin, maxlen);
            dp(s, i, i + 1, begin, maxlen);
        }

        return s.substr(begin, maxlen);
    }
};