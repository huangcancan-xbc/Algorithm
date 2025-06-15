// 牛客：H-Count Circle
// 链接：https://ac.nowcoder.com/acm/contest/105851/H

// 方法：找规律
#include <iostream>
#include <string>
using namespace std;

int is(int x)
{
    int ret = 0;
    string s = to_string(x);                                // 将整数x转换为字符串
    for (auto x : s)                                        // 遍历字符串s
    {
        if (x == '0' || x == '4' || x == '6' || x == '9')
        {
            ret++;                                          // 如s中有0、4、6、9，则ret加1
        }
        else if (x == '8')
        {
            ret += 2;                                       // 如s中有8，则ret加2
        }
    }

    return ret;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int a = 0, b = 0;
        int ret = 0;
        cin >> a >> b;
        if (a == b)
        {
            cout << is(a) << endl;          // 特殊情况：如果a=b，则只需要判断一个数存在“圈”的情况，输出结果并跳过这轮循环
            continue;
        }

        for (int i = a; i <= b; i++)
        {
            ret += is(i);                   // 如果a!=b，则遍历a到b的所有数，并判断每个数是否存在“圈”的情况
        }

        cout << ret << endl;

    }

    return 0;
}