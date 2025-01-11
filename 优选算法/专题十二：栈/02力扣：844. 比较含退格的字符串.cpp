//力扣：844. 比较含退格的字符串
//链接：https://leetcode.cn/problems/backspace-string-compare/description/


//方法一：双指针
class Solution 
{
public:
    bool backspaceCompare(string s, string t) 
    {
        int ss = s.size() - 1;                  // 指向字符串 s 的末尾
        int tt = t.size() - 1;                  // 指向字符串 t 的末尾
        int skip1 = 0, skip2 = 0;               // 跳过字符计数器

        while (ss >= 0 || tt >= 0)              // 直到两个指针都越界
        {
            // 处理字符串 s 中的 '#' 字符
            while (ss >= 0) 
            {
                if (s[ss] == '#') 
                {
                    skip1++;
                    ss--;
                }
                else if (skip1 > 0) 
                {
                    skip1--;
                    ss--;
                }
                else 
                {
                    break;
                }
            }

            // 处理字符串 t 中的 '#' 字符
            while (tt >= 0) 
            {
                if (t[tt] == '#') 
                {
                    skip2++;
                    tt--;
                }
                else if (skip2 > 0) 
                {
                    skip2--;
                    tt--;
                }
                else 
                {
                    break;
                }
            }

            // 比较当前字符
            if (ss >= 0 && tt >= 0) 
            {
                if (s[ss] != t[tt]) 
                {
                    return false;
                }
            }
            else if (ss >= 0 || tt >= 0)            // 如果只有一个指针越界，说明不相等
            { 
                return false;
            }

            // 继续向前移动指针
            ss--;
            tt--;
        }

        return true;                                // 如果同时越界，返回 true
    }
};



//算法原理：
//由于退格的时候需要知道「前⾯元素」的信息，⽽且退格也符合「后进先出」的特性。因此我们可以使⽤「栈」结构来模拟退格的过程。
//• 当遇到⾮ # 字符的时候，直接进栈；
//• 当遇到 # 的时候，栈顶元素出栈。
//为了⽅便统计结果，我们使⽤「数组」来模拟实现栈结构。
//方法二：模拟栈
class Solution 
{
public:
    bool backspaceCompare(string s, string t)
    {
        string s1, s2;
        for (auto x : s)
        {
            if (s1.size() && x == '#')
            {
                s1.pop_back();
            }
            else if (x != '#')
            {
                s1 += x;
            }
        }

        for (auto x : t)
        {
            if (s2.size() && x == '#')
            {
                s2.pop_back();
            }
            else if (x != '#')
            {
                s2 += x;
            }
        }

        return s1 == s2;
    }
};

class Solution 
{
public:
    bool backspaceCompare(string s, string t)
    {
        return check(s) == check(t);
    }

    string check(string s)
    {
        string ret;
        for (auto x : s)
        {
            if (x != '#')
            {
                ret += x;
            }
            else
            {
                if (ret.size())                 // 防止空字符串
                {
                    ret.pop_back();
                }
            }
        }

        return ret;
    }
};



//方法三：栈
class Solution 
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1, s2;
        for (auto x : s)
        {
            if (!s1.empty() && x == '#')
            {
                s1.pop();
            }
            else if (x != '#')
            {
                s1.push(x);
            }
        }

        for (auto x : t)
        {
            if (!s2.empty() && x == '#')
            {
                s2.pop();
            }
            else if (x != '#')
            {
                s2.push(x);
            }
        }

        string ret1, ret2;
        while (!s1.empty())
        {
            ret1 += s1.top();
            s1.pop();
        }

        while (!s2.empty())
        {
            ret2 += s2.top();
            s2.pop();
        }

        return ret1 == ret2;                    // 可以不用反转，不会影响结果
    }
};