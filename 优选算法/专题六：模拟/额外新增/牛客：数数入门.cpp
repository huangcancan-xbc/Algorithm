// 牛客：数数入门
// 链接：https://ac.nowcoder.com/acm/contest/101921/B

// 方法：模拟
#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    while (k--)                             // 循环处理每一个测试用例
    {
        int n;
        cin >> n;                           // 读取当前测试用例中的数列大小

        int arr[1001][1001] = { 0 };        // 创建一个二维数组 arr，用来存储每一行的数列，初始化为 0，可以避免访问未初始化的值
        bool flag = true;                   // 用于标记当前数列是否满足条件，默认为true，表示满足

        // 读取数列的每一行数据
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cin >> arr[i][j];           // 读取当前行的每个数值
            }
        }

        // 开始判断数列的合法性
        for (int i = 1; i < n; ++i)         // 遍历每一行（除了最后一行）
        {
            for (int j = 1; j <= i; ++j)    // 遍历当前行的每个元素
            {
                // 判断当前行的元素是否小于等于下一行的同列元素，以及下一行的右侧元素，如果不满足条件，标记 flag 为 false，并跳出循环
                if (!(arr[i][j] <= arr[i + 1][j] && arr[i][j] <= arr[i + 1][j + 1]))
                {
                    flag = false;           // 不满足条件
                    break;                  // 跳出当前循环，停止进一步判断
                }
            }

            if (!flag)
            {
                break;                      // 如果发现不符合条件，直接跳出外层循环，结束当前测试用例的判断
            }
        }

        // 输出结果，如果 flag 为 true，说明符合条件，输出 "Yes"，否则输出 "No"
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}