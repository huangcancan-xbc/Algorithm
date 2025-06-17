// 牛客：小紫的优势博弈
// 链接：https://ac.nowcoder.com/acm/contest/103948/D

// 方法：模拟
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int fenzi = 0;

    for (int i = 0; i < n; i++)             // 枚举每个起点 i（模拟小红的操作）
    {
        int cnt_0 = 0;                      // 统计 0 的数量
        int cnt_1 = 0;                      // 统计 1 的数量

        for (int j = i + 1; j < n; j++)     // 从 i+1 开始寻找满足条件的子串（模拟小紫的操作）
        {
            if (s[j] == '1')
            {
                cnt_1++;                    // 统计 '1' 的数量
            }
            else
            {
                cnt_0++;                    // 统计 '0' 的数量
            }

            // 判断当前子串是否满足 0 和 1 的数量均为偶数的条件
            if (cnt_0 % 2 == 0 && cnt_1 % 2 == 0)
            {
                fenzi++;                    // 只要找到符合条件的子串，计数器加一，即可以获胜的次数加 1
                break;                      // 满足条件后立即结束内层循环
            }
        }
    }


    double ans = (double)fenzi / n;         // 计算满足条件的子串对数与总长度 n 的比值
    cout << ans << endl;

    return 0;
}