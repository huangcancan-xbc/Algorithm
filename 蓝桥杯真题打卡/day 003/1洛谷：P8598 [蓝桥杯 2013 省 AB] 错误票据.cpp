//洛谷：P8598 [蓝桥杯 2013 省 AB] 错误票据
//链接：https://www.luogu.com.cn/problem/P8598


//方法：
//因为 cin 不能读到空格和换行，我们只需要一直读到输入流结束即可。
//然后对输入的数组进行排序，然后遍历数组，如果当前元素和下一个元素的差值大于1，说明有错误票据，记录下这个错误票据的第一个元素。
//如果当前元素和下一个元素相同，说明有错误票据，记录下这个错误票据的第一个元素。
//最后输出错误票据的第一个元素和第二个元素。
#include <iostream>
#include <algorithm>
using namespace std;

int n, len;
int arr[100010];
int main()
{
    cin >> n;

    while (cin >> arr[len])
    {
        len++;                                  // 记录输入的数组长度
    }

    sort(arr, arr + len);

    int condition1 = 0, condition2 = 0;         // 记录缺少的元素和重复的元素
    for (int i = 1; i < len - 1; i++)
    {
        if (arr[i + 1] - arr[i] > 1)
        {
            condition1 = arr[i] + 1;            // 缺少的元素
        }
        if (arr[i] == arr[i + 1])
        {
            condition2 = arr[i];                // 重复的元素
        }

        if (condition1 && condition2)           // 找到后退出循环
        {
            break;
        }
    }

    cout << condition1 << " " << condition2;    // 输出结果

    return 0;
}