//洛谷：P10424 [蓝桥杯 2024 省 B] 好数
//链接：https://www.luogu.com.cn/problem/P10424


//方法：枚举
#include <iostream>
using namespace std;
int main()
{
    int n, ret = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int k = 1, temp = i, flag = 0;                  // flag = 1 表示不是好数
        while (temp)                                    // 计算每位数字的奇偶性
        {
            if (k % 2 == 1 && temp % 2 != 1)            // 如果该位是奇数，数字不是奇数，则不是好数
            {
                flag = 1;                               // 标记为不是好数，跳出循环
                break;
            }
            if (k % 2 == 0 && temp % 2 != 0)            // 如果该位是偶数，数字不是偶数，则不是好数
            {
                flag = 1;                               // 标记为不是好数，跳出循环
                break;
            }

            k++, temp /= 10;                            // 计算下一位
        }

        if (flag)                                       // 如果不是好数，跳过
        {
            continue;
        }
        else                                            // 如果是好数，计数
        {
            ret++;
        }
    }

    cout << ret;

    return 0;
}




#include <iostream>
using namespace std;
bool is(int n)
{
    int x = n, y = 0;
    int i = 0;                      // 记录位数
    while (x)
    {
        i++;
        y = x % 10;                 // 取出最后一位
        if (i % 2 != y % 2)         // 奇数位和偶数位不相同就返回false
        {
            return false;
        }

        x /= 10;                    // 准备进行下位比较
    }

    return true;
}
int main()
{
    int n = 0;
    cin >> n;

    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (is(i))
        {
            ret++;
        }
    }

    cout << ret;
    return 0;
}