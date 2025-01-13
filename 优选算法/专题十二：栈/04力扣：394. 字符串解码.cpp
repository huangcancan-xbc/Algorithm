//力扣：394. 字符串解码
//链接：https://leetcode.cn/problems/decode-string/description/


//方法：双栈模拟

//算法原理：
//对于 3[ab2[cd]] ，我们需要先解码内部的，再解码外部（为了⽅便区分，使⽤了空格）：
//    • 3[ab2[cd]] -> 3[abcd cd]->abcdcd abcdcd abcdcd
//
//在解码 cd 的时候，我们需要保存 3 ab 2 这些元素的信息，并且这些信息使⽤的顺序是从后往前，
//正好符合栈的结构，因此我们可以定义两个栈结构，⼀个⽤来保存解码前的重复次数 k （左括号前的数字），
//⼀个⽤来保存解码之前字符串的信息（左括号前的字符串信息）。
class Solution 
{
public:
    string decodeString(string s)
    {
        stack<string> st;                                   // 字符串栈
        stack<int> num;                                     // 数字栈
        st.push("");
        int i = 0, n = s.size();

        while (i < n)                                       // 遍历字符串
        {
            if (s[i] >= '0' && s[i] <= '9')                 // 如果是数字
            {
                // 提取数字放进数字栈
                int temp = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    temp = temp * 10 + (s[i++] - '0');      // 注意 i 的自增，下次循环从下一个字符开始
                }

                num.push(temp);                             // 数字入栈
            }
            else if (s[i] == '[')                           // 如果是左括号
            {
                i++;                                        //跳过这个字符

                // 提取字符串放进字符串栈
                string temp;
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    temp += s[i++];                         // 注意 i 的自增，下次循环从下一个字符开始
                }

                st.push(temp);
            }
            else if (s[i] == ']')                           // 如果是右括号
            {
                string temp = st.top();                     // 取出字符串栈顶元素，作为重复次数，并弹出
                st.pop();
                int k = num.top();                          // 取出重复次数，并弹出
                num.pop();

                while (k--)
                {
                    st.top() += temp;                       // 重复字符串并入栈
                }

                i++;                                        // 注意跳过右括号这个字符
            }
            else                                            // 如果是单独的字符，直接提取并加入字符串栈顶的字符串的末尾
            {
                string temp;
                while (s[i] >= 'a' && s[i] <= 'z')
                {
                    temp += s[i++];
                }

                st.top() += temp;
            }
        }

        return st.top();                                    // 经过双栈的操作，最终只有一个字符串栈，返回栈顶元素即为解码后的字符串
    }
};



//函数版本：
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;                                   // 字符串栈
        stack<int> num;                                     // 数字栈
        st.push("");
        int i = 0, n = s.size();

        while (i < n)                                       // 遍历字符串
        {
            if (isdigit(s[i]))                              // 如果是数字
            {
                // 提取数字放进数字栈
                int temp = 0;
                while (isdigit(s[i]))
                {
                    temp = temp * 10 + (s[i++] - '0');      // 注意 i 的自增，下次循环从下一个字符开始
                }

                num.push(temp);                             // 数字入栈
            }
            else if (s[i] == '[')                           // 如果是左括号
            {
                i++;                                        //跳过这个字符

                // 提取字符串放进字符串栈
                string temp;
                while (isalpha(s[i]))
                {
                    temp += s[i++];                         // 注意 i 的自增，下次循环从下一个字符开始
                }

                st.push(temp);
            }
            else if (s[i] == ']')                           // 如果是右括号
            {
                string temp = st.top();                     // 取出字符串栈顶元素，作为重复次数，并弹出
                st.pop();
                int k = num.top();                          // 取出重复次数，并弹出
                num.pop();

                while (k--)
                {
                    st.top() += temp;                       // 重复字符串并入栈
                }

                i++;                                        // 注意跳过右括号这个字符
            }
            else                                            // 如果是单独的字符，直接提取并加入字符串栈顶的字符串的末尾
            {
                string temp;
                while (isalpha(s[i]))
                {
                    temp += s[i++];
                }

                st.top() += temp;
            }
        }

        return st.top();                                    // 经过双栈的操作，最终只有一个字符串栈，返回栈顶元素即为解码后的字符串
    }
};