// 牛客：Tk王国的括号
// 链接：https://ac.nowcoder.com/acm/contest/111922/C

// 方法：括号匹配
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    unordered_set<string> hash;
    for (int i = 0; i < 13; ++i)
    {
        string s1 = "";
        s1 += ('a' + i);            // 构造前一个字符
        s1 += ('z' - i);            // 构造后一个字符
        hash.insert(s1);            // 加入哈希表
    }

    for (int j = 0; j < 13; ++j)
    {
        string s2 = "";
        s2 += ('Z' - j);            // 构造前一个字符
        s2 += ('A' + j);            // 构造后一个字符
        hash.insert(s2);            // 加入哈希表
    }

    stack<char> st;

    for (char c : s)
    {
        if (!st.empty())            // 栈不为空
        {
            string temp = "";
            temp += st.top();       // 栈顶元素就是前一个字符
            temp += c;              // 当前字符即后一个字符

            if (hash.count(temp))   // 如果存在这个子串
            {
                st.pop();           // 弹出栈顶元素
                continue;           // 跳过本次，不将当前字符入栈
            }
        }

        st.push(c);                 // 其他情况，入栈
    }

    cout << st.size() << endl;
    return 0;
}



// “指针模拟”写法：
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    unordered_set<string> hash;
    for (int i = 0; i < 13; ++i)
    {
        string s1 = "";
        s1 += ('a' + i);
        s1 += ('z' - i);
        hash.insert(s1);
    }

    for (int j = 0; j < 13; ++j)
    {
        string s2 = "";
        s2 += ('Z' - j);
        s2 += ('A' + j);
        hash.insert(s2);
    }

    int ret = 0;

    for (int i = 0; i < n; ++i)
    {
        if (ret > 0)
        {
            string testPair = "";
            testPair += s[ret - 1];
            testPair += s[i];

            if (hash.count(testPair))
            {
                --ret;
                continue;
            }
        }

        s[ret++] = s[i];
    }

    cout << ret << endl;
    return 0;
}