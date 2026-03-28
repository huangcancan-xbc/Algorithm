// PTA：L1-111 大幂数
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=1913922872972247046&page=1

// 方法：暴力枚举
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long x;
    cin >> x;

    for (int i = 30; i >= 1; i--)
    {
        long sum = 0;
        for (int j = 1; j < 100000; j++)
        {
            sum += pow(j, i);
            if (sum == x)
            {
                for (int k = 1; k <= j; k++)
                {
                    cout << k << "^" << i;
                    if (k != j)
                    {
                        cout << "+";
                    }
                }

                return 0;
            }
        }
    }

    cout << "Impossible for " << x << "." << endl;
    return 0;
}