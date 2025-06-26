// 洛谷：P8772 [蓝桥杯 2022 省 A] 求和
// 链接：https://www.luogu.com.cn/problem/P8772


// 方法一：暴力求解
// 时间复杂度 O(n^2)（会超时）
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long ret = 0;

    // 双重循环计算所有两两元素乘积的和
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ret += nums[i] * nums[j];
        }
    }

    cout << ret;

    return 0;
}



// 方法二：利用前缀和优化
// 时间复杂度 O(n)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<long long> nums(n + 1, 0);           // 前缀和数组，初始化为 0
    vector<int> arr(n + 1, 0);                  // 存储输入的原数组
    long long ret = 0;                          // 结果变量

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];                          // 输入原数组元素
        nums[i] = nums[i - 1] + arr[i];         // 计算前缀和
    }

    // 利用前缀和优化计算两两元素乘积的和
    for (int i = 1; i <= n - 1; i++)
    {
        ret += arr[i] * (nums[n] - nums[i]);    // arr[i] * (nums[n] - nums[i]) 表示 arr[i] 依次与后续所有元素相乘的和
    }

    cout << ret;                                // 输出结果

    return 0;
}
//思路：
//假设有 a b c d e 五个数：
//前缀和优化方式：
//创建一个前缀和数组：
//[a] [a+b] [a+b+c] [a+b+c+d] [a+b+c+d+e]
//如：
//• 对于元素 a，存在这样的应用：
//a * b = a * ([a+b] - [a])
//a * c = a * ([a+b+c] - [a+b])
//……
//• 总体计算为：
//元素 arr[i] 与其后续元素乘积：arr[i] * (nums[n] - nums[i])
//导致循环次数降低，性能显著优化。




//方法三：数学方法
//方法来源：https://www.luogu.com.cn/article/pn89mqud
//时间复杂度 O(n)
#include <iostream>
#include <vector>
using namespace std;
long long n, x, mul = 0, sum = 0;           // mul 存储所有元素的乘积，sum 存储所有元素的平方和
int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x;
        sum += (x * x);
        mul += x;
    }

    cout << (mul * mul - sum) / 2;
    return 0;
}