//牛客：斐波那契
//https://ac.nowcoder.com/acm/contest/97845/L
//参赛密码：517acm


#include <iostream>
using namespace std;

//方法一：循环
int main()
{
    int k = 0;
    cin >> k;
    k -= 2;

    long long ret = 1, a = 1, b = 0;
    
    while (k--)
    {
        b = ret + a;
        ret = a;
        a = b;
    }

    cout << b << endl;
    return 0;
}


//方法二：递归
#include <iostream>
using namespace std;

long long dp(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    return dp(n - 1) + dp(n - 2);
}

int main()
{
    int k = 0;
    cin >> k;
 
    long long ret = dp(k);

    cout << ret << endl;
    return 0;
}



//方法三：优化递归
//上面递归差不多在30、40层就超时了，所以可以优化一下，使用数组存储中间结果 
#include <iostream>
using namespace std;
long long f[100];
long long dp(int n)
{
    if (f[n] != 0)                          // 优化：使用数组存储中间结果，避免重复计算
    {
        return f[n];
    }

    if (n == 1 || n == 2)
    {
        return 1;
    }

    // 优化：使用数组存储中间结果
    return f[n] = dp(n - 1) + dp(n - 2);

}

int main()
{
    int k = 0;
    cin >> k;

    long long ret = dp(k);

    cout << ret << endl;
    return 0;
}