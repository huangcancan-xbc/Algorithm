// 牛客：小苯的数字消除
// 链接：https://ac.nowcoder.com/acm/contest/104637/C

// 方法：栈
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int is(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);                  // 如果栈为空，则压入字符
        }
        else                                // 如果栈不为空，则比较栈顶字符和当前字符
        {
            if (s[i] != st.top())
            {
                st.push(s[i]);              // 如果当前字符和栈顶字符不同，则压入字符
            }
            else
            {
                st.pop();                   // 如果当前字符和栈顶字符相同，则弹出栈顶字符
            }
        }
    }

    return st.size() / 2;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;

        int ret = is(s);
        cout << ret << endl;
    }

    return 0;
}