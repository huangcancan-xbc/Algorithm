// PTA：L1-002 打印沙漏
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805145370476544&page=1

// 方法：模拟 + 数学
#include <iostream>
using namespace std;
int main()
{
    int n = 0, sum = 1;
    char ch;
    cin >> n >> ch;

    int k = 1;// 设 k 为层数，注意：k 需要初始化为 1，如果是 0 ，下一步循环 sum 会加上一个偶数2，导致后续错误
    while (sum + (2 * k + 1) * 2 <= n)          // 根据等差数列求和公式，计算层数
    {
        sum += (2 * k + 1) * 2;
        k++;
    }
    k--;

    int ret = n - sum;

    // 打印上半部分
    for (int i = k; i >= 0; i--)
    {
        for (int j = 0; j < k - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
        }

        cout << endl;
    }

    // 打印下半部分
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < k - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << ch;
        }

        cout << endl;
    }

    cout << ret << endl;                        // 打印剩余的数字个数

    return 0;
}