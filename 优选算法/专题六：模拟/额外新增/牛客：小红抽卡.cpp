// 牛客：小红抽卡
// 链接：https://ac.nowcoder.com/acm/contest/117763/C

// 方法：模拟 + 数学剪枝
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 构造置换 P：位置 i -> 新位置
    vector<int> P(n + 1);
    // 把第 x 张牌移到最前
    P[x] = 1;
    // 前 x-1 张牌整体往后移一格
    for (int i = 1; i < x; i++) P[i] = i + 1;
    // 后面的保持相对顺序
    for (int i = x + 1; i <= n; i++) P[i] = i;

    // ret[pos] = 最终在该位置的牌
    vector<int> ret(n + 1, 0);
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        // 找到环
        vector<int> huan;
        int cur = i;
        while (!vis[cur])
        {
            vis[cur] = 1;
            huan.push_back(cur);
            cur = P[cur];
        }

        int L = huan.size();
        // 在环中移动 k mod L 步
        for (int j = 0; j < L; j++)
        {
            int temp = huan[j];
            int to = huan[(j + k % L) % L];
            ret[to] = a[temp];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ret[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}