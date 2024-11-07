//牛客：DP34 【模板】前缀和
//https://www.nowcoder.com/practice/acead2f4c28c401889915da98ecdc6bf?tpId=230&tqId=2021480&ru=%2Fpractice%2F99eb8040d116414ea3296467ce81cbbc&qru=%2Fta%2Fdynamic-programming%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D196


//方法一：暴力解法-->模拟
//时间复杂度：O(n*q)
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n = 0, q = 0;               // 定义 n (数组长度) 和 q (查询次数)
    cin >> n >> q;                        // 输入数组长度和查询次数

    vector<long long> v(n + 1);           // 定义原始数组，大小为 n+1 便于从索引 1 开始
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];                      // 输入数组元素
    }

    long long l = 0, r = 0;               // 定义左右边界
    while (q--)                           // 处理每个查询
    {
        cin >> l >> r;                    // 输入查询区间的左、右边界
        long long ans = 0;                // 存储当前查询的区间和
        for (long long i = l; i <= r; i++)
        {
            ans += v[i];                  // 累加区间内的元素
        }
        cout << ans << endl;              // 输出当前查询的结果
    }

    return 0;                             // 程序结束
}








//方法二:前缀和（可以快速计算数组中某一个连续区间的和）
//时间复杂度：O(n)

//算法原理：
//1.第一步：预处理出来一个前缀和数组
//        i. dp[i] 表示 [1,i] 区间内所有元素的和
//        ii. dp[i] = dp[i-1] + arr[i]
//2.第二步：使用前缀和数组
//        i. 查询区间 [l,r] 的和为 dp[r] - dp[l-1]
//        ii. 时间复杂度：O(1)

//疑问（细节问题）：为什么我们是下标要从 1 开始计数呢？
//答：主要是为了处理边界情况。（初始化：添加虚拟节点/辅助节点，使得数组下标从 1 开始计数）
//例如：dp[0] = 0，dp[1] = arr[1]，dp[i] = dp[i-1] + arr[i]，则 dp[n] 存储的是数组 arr[1] 到 arr[n] 的累加和。
//因此，我们在查询时，需要将查询区间的左右边界 l,r 都减 1 才能得到正确的前缀和。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n = 0, q = 0;           // 定义 n (数组长度) 和 q (查询次数)
    cin >> n >> q;                    // 输入数组长度和查询次数

    vector<long long> v(n + 1);       // 定义原始数组，大小为 n+1 (便于从索引 1 开始)
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];                  // 输入数组元素
    }

    vector<long long> dp(n + 1);      // 定义前缀和数组
    for (long long i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + v[i];     // 计算前缀和：dp[i] 存储 v[1] 到 v[i] 的累加和
    }

    long long l = 0, r = 0;           // 查询区间的左右边界
    long long ans = 0;                // 存储查询结果
    while (q--)                       // 处理每次查询
    {
        cin >> l >> r;                // 输入查询区间的左、右边界
        ans = dp[r] - dp[l - 1];      // 使用前缀和快速计算区间和
        cout << ans << endl;          // 输出当前查询的结果
    }

    return 0;                         // 程序结束
}







#include <iostream>

using namespace std;

const int N = 100010;                 // 定义数组最大长度
long long arr[N], dp[N];              // 原始数组和前缀和数组
int n, q;                             // 定义 n (数组长度) 和 q (查询次数)

int main()
{
    cin >> n >> q;                    // 输入数组长度和查询次数

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];                // 输入数组元素
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + arr[i];   // 计算前缀和：dp[i] 为 arr[1] 到 arr[i] 的累加和
    }

    while (q--)                       // 处理每次查询
    {
        int l = 0, r = 0;             // 查询区间的左右边界
        cin >> l >> r;                // 输入查询区间的左、右边界
        cout << dp[r] - dp[l - 1] << endl;// 使用前缀和快速计算区间和并输出结果
    }

    return 0;                         // 程序结束
}
