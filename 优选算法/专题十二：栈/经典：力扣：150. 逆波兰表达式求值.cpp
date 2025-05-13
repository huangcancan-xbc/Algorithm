//力扣：150. 逆波兰表达式求值
//https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/


class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (auto x : tokens)
        {
            if (x == "+" || x == "-" || x == "*" || x == "/")           // 如果 x 是运算符
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();

                if (x == "+") st.push(n2 + n1);
                if (x == "-") st.push(n2 - n1);
                if (x == "*") st.push(n2 * n1);
                if (x == "/") st.push(n2 / n1);
            }
            else                                                        // 如果 x 是数字
            {
                st.push(stoi(x));                                       // 将字符串转换为整数
            }
        }

        return st.top();                                                // 返回最终结果
    }
};
//注意：字符类型和字符串类型的混淆。使用了字符（char）类型来比较字符串（string）类型的值。
//例如，写了 if (x == '+' || x == '-' || x == '*' || x == '/')，这会导致条件判断始终为假，
//因为 x 是 string 类型，而 '+'、'-' 等是 char 类型。C++ 中，字符类型和字符串类型不能直接比较，因此需要保持类型一致。

//总结
//1. 确保比较时类型一致：如果 x 是 string 类型，与其比较的值也应该是 string 类型（例如 "+"）。
//2. 避免混用 char 和 string：在 C++ 中，char 和 string 是不同的类型，char 用单引号（'+'），而 string 用双引号（"+"）。