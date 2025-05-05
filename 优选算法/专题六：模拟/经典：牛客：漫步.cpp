// 牛客：漫步
// 链接：https://ac.nowcoder.com/acm/contest/106318/D

// 方法：虚假的二进制，真实的模拟

// 方法一：我最初的方法——二进制，超时
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
    int t = 0;
    scanf("%d", &t);

    while (t--)
    {
        long long x = 0;
        scanf("%lld", &x);

        long long ret = -1;
        for (int i = 1; i < sqrt(x); i++)
        {
            int temp = x + i;
            if ((x & temp) == x || (x & temp) == temp)
            {
                ret = i;
                break;
            }
        }

        printf("%lld\n", ret);
    }

    return 0;
}



// 方法二：模拟，根据题目要求找答案，只要要求的位置为1即可，我们从这个数的二进制位最右边开始找一个0的位置，
// 把他改成1，就是答案（从右往左保证了数会小一点并且不溢出）
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t = 0;
    scanf("%d", &t);

    while (t--)
    {
        long long x;
        scanf("%lld", &x);
        long long ret = x;

        // 找到 x 二进制右边的第一个0的位置
        int pos = 0;
        long long temp = x;

        while (temp & 1)
        {
            temp >>= 1;
            pos++;
        }

        if ((ret & (ret + 1)) == 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", (1LL << pos));
        }
    }

    return 0;
}