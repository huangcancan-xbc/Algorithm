//洛谷：P9241 [蓝桥杯 2023 省 B] 飞机降落
//链接：https://www.luogu.com.cn/problem/P9241


#include <iostream>
#include <cstring>
using namespace std;
struct Node
{
    int l; // 飞机最早能降落的时间
    int r; // 飞机最晚能降落的时间
    int t; // 飞机降落需要的时间
};

int t, n, vis[15];
bool flag;                                          // 用于标记是否可以完成所有飞机的降落
Node fj[15];

void dfs(int deep, int now)                         // deep 是当前降落的飞机数量, now 是当前时间
{ 
    if (deep == n)                                  // 所有飞机都已成功降落
    {
        flag = 1;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && fj[i].r < now) return;       // 剪枝：如果该飞机的最晚降落时间已经过了，则剪掉

        if (!vis[i] && fj[i].r >= now)              // 如果该飞机还没有被降落并且最晚降落时间还没过
        {
            vis[i] = 1;                             // 标记该飞机已降落

            // 如果该飞机的最早降落时间比当前时间晚，说明它只能在最早降落时间后开始
            if (fj[i].l > now)
            {
                dfs(deep + 1, fj[i].l + fj[i].t);   // 更新当前时间为它的降落完成时间
            }
            else
            {
                dfs(deep + 1, now + fj[i].t);       // 否则直接在当前时间开始降落
            }

            vis[i] = 0;                             // 取消标记，回溯
        }
    }
}

int main()
{
    cin >> t;
    memset(vis, 0, sizeof(vis));                    // 初始化访问数组

    while (t--) 
    {
        cin >> n;
        flag = 0;
        int k;

        // 读取每架飞机的到达时刻、最多等待时间和降落时间
        for (int i = 1; i <= n; i++)
        {
            cin >> fj[i].l >> k >> fj[i].t;
            fj[i].r = fj[i].l + k;                  // 最晚降落时间为最早降落时间加上最大等待时间
        }

        // 尝试所有飞机的降落顺序
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 1;                             // 标记第 i 架飞机开始降落
            dfs(1, fj[i].l + fj[i].t);              // 从飞机 i 开始降落，当前时间为它的降落完成时间
            vis[i] = 0;                             // 取消标记
        }

        if (flag) cout << "YES" << endl;            // 如果所有飞机都能按顺序降落，输出 YES
        else cout << "NO" << endl;                  // 否则输出 NO
    }

    return 0;
}