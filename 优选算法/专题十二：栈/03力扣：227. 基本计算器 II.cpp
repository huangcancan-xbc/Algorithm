//力扣：227. 基本计算器 II
//链接：https://leetcode.cn/problems/basic-calculator-ii/description/


//方法一：模拟栈

//算法原理：
//1. 初始化运算符，因为 1+2+3 相当于 +1+2+3 ，因此初始化运算符为 +。遇到运算符进行更新
//2. 遇到数字：
//    a. 先把数字提取出来，这里用一个变量 temp 进行存储
//    b. 根据 symbol 符号进行分情况讨论：
//        i. 如果 symbol 是 +，则把 temp 压入栈中
//        ii. 如果 symbol 是 -，则把 -temp 压入栈中
//        iii. 如果 symbol 是 *，则栈顶元素乘以 temp 压入栈中·
//        iv. 如果 symbol 是 /，则栈顶元素除以 temp 压入栈中
//3. 最后把栈中所有元素相加，即为结果

//时间复杂度：O(n)，其中 n 是字符串 s 的长度。
class Solution
{
public:
    int calculate(string s)
    {
        vector<int> st;
        int n = s.size(), i = 0;
        char symbol = '+';

        while (i < n)                                           // 遍历字符串，确保不越界
        {
            if (s[i] == ' ')                                    // 如果是空格，就直接跳过
            {
                i++;
            }
            else if (s[i] >= '0' && s[i] <= '9')                // 如果是数字
            {
                // 提取数字
                int temp = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    temp = temp * 10 + (s[i++] - '0');          // 提取数字
                }

                // 根据 symbol 符号进行分情况讨论
                if (symbol == '+')
                {
                    st.push_back(temp);
                }
                else if (symbol == '-')
                {
                    st.push_back(-temp);
                }
                else if (symbol == '*')
                {
                    st.back() *= temp;
                }
                else if (symbol == '/')
                {
                    st.back() /= temp;
                }
            }
            else                                                // 如果是运算符
            {
                symbol = s[i];                                  // 更新符号
                i++;                                            // 跳过符号，进行运算
            }
        }

        // 最后把栈中所有元素相加
        int ret = 0;
        for (auto x : st)
        {
            ret += x;
        }

        return ret;
    }
};

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> st;
        int n = s.size(), i = 0;
        char symbol = '+';

        while (i < n)
        {
            if (s[i] == ' ')
            {
                i++;
            }
            else if (isdigit(s[i]))                             // 如果是数字
            {
                // 提取数字
                int temp = 0;
                while (i < n && isdigit(s[i]))
                {
                    temp = temp * 10 + (s[i++] - '0');          // 提取数字
                }

                // 根据 symbol 符号进行分情况讨论
                if (symbol == '+')
                {
                    st.push_back(temp);
                }
                else if (symbol == '-')
                {
                    st.push_back(-temp);
                }
                else if (symbol == '*')
                {
                    st.back() *= temp;
                }
                else if (symbol == '/')
                {
                    st.back() /= temp;
                }
            }
            else
            {
                symbol = s[i];
                i++;
            }
        }

        // 最后把栈中所有元素相加
        int ret = 0;
        for (auto x : st)
        {
            ret += x;
        }

        return ret;
    }
};




//方法二：双栈
//算法原理：
//1. 初始化两个栈，一个数字栈 num，一个运算符栈 symbol
//2. 遍历字符串，遇到数字就把数字压入数字栈，遇到运算符就把运算符压入运算符栈
//3. 遇到 * 或 / 时，就把数字栈顶元素弹出，计算结果，再把结果压入数字栈
//4. 遇到 + 或 - 时，分别将数字和它的相反数压入数字栈
//5. 最后把数字栈中所有元素相加，即为结果

//时间复杂度：O(n)，其中 n 是字符串 s 的长度。
class Solution 
{
public:
    int calculate(string s)
    {
        stack<int> num;                                     // 数字栈
        stack<char> symbol;                                 // 运算符栈
        int i = 0, n = s.size();
        int ret = 0;                                        // 结果集

        while (i < n)
        {
            if (s[i] == ' ')                                // 如果是空格，就直接跳过
            {
                i++;
            }
            else if (isdigit(s[i]))                         // 如果是数字
            {
                int temp = 0;
                while (i < n && isdigit(s[i]))
                {
                    temp = temp * 10 + (s[i++] - '0');      // 先把数字提取出来
                }

                // 根据 symbol 符号进行分情况讨论
                if (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/'))    // 如果栈顶是 * 或 /，直接计算（优先级高先算）
                {
                    char ch = symbol.top();                 // 取出栈顶运算符，再弹出栈顶元素
                    symbol.pop();
                    int x = num.top();                      // 取出栈顶数字，再弹出栈顶元素
                    num.pop();

                    // 直接计算 * 或 / 的结果
                    if (ch == '*')
                    {
                        num.push(x * temp);
                    }
                    else if (ch == '/')
                    {
                        num.push(x / temp);
                    }
                }
                else if (!symbol.empty() && symbol.top() == '-')                       // 如果是 - 号，就把 -temp 压入栈中
                {
                    num.push(-temp);
                }
                else
                {
                    num.push(temp);                         // 如果是 + 号，就把 temp 压入栈中
                }
            }
            else                                            // 如果是运算符
            {
                symbol.push(s[i++]);                        // 直接压入栈中
            }
        }

        // 最后把栈中所有元素相加
        while (!num.empty())
        {
            ret += num.top();
            num.pop();
        }

        return ret;
    }
};