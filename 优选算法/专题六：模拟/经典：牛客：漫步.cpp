// ţ�ͣ�����
// ���ӣ�https://ac.nowcoder.com/acm/contest/106318/D

// ��������ٵĶ����ƣ���ʵ��ģ��

// ����һ��������ķ������������ƣ���ʱ
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



// ��������ģ�⣬������ĿҪ���Ҵ𰸣�ֻҪҪ���λ��Ϊ1���ɣ����Ǵ�������Ķ�����λ���ұ߿�ʼ��һ��0��λ�ã�
// �����ĳ�1�����Ǵ𰸣���������֤������Сһ�㲢�Ҳ������
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

        // �ҵ� x �������ұߵĵ�һ��0��λ��
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