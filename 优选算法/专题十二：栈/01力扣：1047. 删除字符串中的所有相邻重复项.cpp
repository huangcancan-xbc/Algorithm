//力扣：1047. 删除字符串中的所有相邻重复项
//链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
//算法原理：
//本题极像我们玩过的「开⼼消消乐」游戏，仔细观察消除过程，可以发现本题与我们之前做过的「括号匹配」问题是类似的。
//当前元素是否被消除，需要知道上⼀个元素的信息，因此可以⽤「栈」来保存信息。
//
//但是，如果使⽤ stack 来保存的话，最后还需要把结果从栈中取出来。不如直接⽤「数组模拟⼀个栈」结构：
//在数组的尾部「尾插尾删」，实现栈的「进栈」和「出栈」。那么最后数组存留的内容，就是最后的结果。

//方法一：模拟栈
class Solution 
{
public:
    string removeDuplicates(string s)
    {
        string st;                                      // 用字符串 st 模拟栈的功能
        for (auto x : s)                                // 遍历输入字符串中的每个字符
        {
            if (!st.empty() && st.back() == x)          // 检查 st 最后一个字符是否与当前字符相同
            {
                st.pop_back();                          // 删除相邻的重复字符
            }
            else {
                st.push_back(x);                        // 添加非重复字符到 st
            }
        }

        return st;                                      // 返回去重后的字符串
    }
};

class Solution 
{
public:
    string removeDuplicates(string s)
    {
        string ret;
        for (auto x : s)
        {
            if (ret.size() && ret.back() == x)          // 检查 ret 最后一个字符是否与当前字符相同并且 “栈” 不为空
            {
                ret.pop_back();                         // 删除相邻的重复字符
            }
            else
            {
                ret += x;                               // 添加非重复字符到 ret
            }
        }

        return ret;
    }
};



//方法二：栈模拟
class Solution 
{
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;                                 // 栈用于存储字符，方便相邻字符的比较
        for (auto x : s)                                // 遍历字符串的每个字符
        {
            if (!st.empty() && x == st.top())           // 如果栈不为空且当前字符与栈顶相同
            {
                st.pop();                               // 出栈，即删除相邻重复的字符
            }
            else {
                st.push(x);                             // 入栈保存字符
            }
        }

        // 构造结果字符串，存储栈中元素
        string ret = "";
        while (!st.empty())
        {
            ret += st.top();
            st.pop();
        }

        reverse(ret.begin(), ret.end());                // 反转字符串得到正确顺序
        return ret;                                     // 返回去重后的字符串
    }
};

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        for (auto x : s)
        {
            if (!st.empty() && x == st.top())           // 如果栈不为空且当前字符与栈顶相同
            {
                st.pop();                               // 出栈，即删除相邻重复的字符
            }
            else
            {
                st.push(x);                             // 入栈保存字符
            }
        }

        string ret;
        while (st.size())
        {
            ret += st.top();                            // 构造结果字符串，存储栈中元素
            st.pop();
        }

        reverse(ret.begin(), ret.end());                // 反转字符串得到正确顺序
        return ret;
    }
};