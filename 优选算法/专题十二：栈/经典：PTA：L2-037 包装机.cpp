// PTA：L2-037 包装机
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1386335159927652360&page=1

// 方法：栈
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n = 0, m = 0, capacity = 0;
    cin >> n >> m >> capacity;
    vector<vector<char>> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            v[i].push_back(c);
        }
    }

    stack<char> st;
    string ret;

    int index;
    while (cin >> index)
    {
        if (index == -1)
        {
            break;
        }

        if (index == 0)
        {
            if (!st.empty())
            {
                ret += st.top();
                st.pop();
            }
        }
        else
        {
            if (v[index].empty())
            {
                continue;
            }

            if (st.size() == capacity)
            {
                if (!st.empty())
                {
                    ret += st.top();
                    st.pop();
                }
            }

            if (st.size() < capacity)
            {
                st.push(v[index].front());
                v[index].erase(v[index].begin());
            }
        }
    }

    cout << ret << endl;

    return 0;
}