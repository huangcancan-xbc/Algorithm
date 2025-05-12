//力扣：1047. 删除字符串中的所有相邻重复项
//https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/


// 方法一：使用 stack 进行相邻重复字符的处理
class Solution {
public:
    string removeDuplicates(string s) {
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




// 方法二：使用字符串模拟栈实现
class Solution {
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