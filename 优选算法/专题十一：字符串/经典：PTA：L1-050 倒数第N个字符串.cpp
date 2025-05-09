// PTA：L1-050 倒数第N个字符串
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805080346181632&page=0

// 方法：字符串模拟、26进制
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int l, n;
    cin >> l >> n;
    string s;
    int sum = pow(26, l) - n;       // 计算正数第 sum + 1 个字符串（从0开始）

    while (sum > 0)
    {
        s += sum % 26 + 'a';        // 取当前最低位
        sum /= 26;                  // 去掉最低位
    }

    while (s.size() < l)
    {
        s += 'a';                   // 补全前导 'a'（相当于数字中的前导零）
    }

    reverse(s.begin(), s.end());    // 反转字符串，因为之前是从低位到高位计算的

    cout << s << endl;
    return 0;
}