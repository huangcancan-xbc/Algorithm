//牛客：太阳系DISCO
//链接：https://ac.nowcoder.com/acm/problem/284006


//BFS 算法的实现：
//1. 初始化：将起点 a - 1 和最大跳跃次数 k 入队，并标记起点为已访问。
//2. BFS 遍历：
//    · 从队列中取出当前节点，尝试所有可能的跳跃：
//        · 跳跃 x 步。
//        · 跳跃 y 步。
//        · 如果剩余的 n / 2 步次数大于 0，跳跃 n / 2 步。
//    · 如果能到达终点，直接返回路径长度。
//    · 如果队列遍历结束都没有到达终点，返回 - 1。
//
//关键操作：
//    跳跃 x 步：当前节点 cur 跳跃 x 步后，新的节点是(cur + x) % n。
//    跳跃 y 步：当前节点 cur 跳跃 y 步后，新的节点是(cur - y + n) % n（加上 n 是为了确保结果不会为负数）。
//    跳跃 n / 2 步：如果还剩下跳跃 n / 2 步的机会，当前节点 cur 跳跃 n / 2 步后，新的节点是(cur + n / 2) % n。
//
//终止条件：
// · 如果当前节点是终点 b - 1，则返回跳跃次数。
// · 如果队列为空，说明没有找到到达终点的路径，返回 - 1。
#include <iostream>
#include <queue>
using namespace std;

int n, k, a, b, x, y;               // n:节点数，k:最大跳跃次数，a:起点，b:终点，x:步长1，y:步长2
queue<pair<int, int>> q;            // 队列存储当前节点和剩余步数
int path[300010];                   // 存储每个节点的最短步数

// 深度优先搜索（广度优先搜索）的实现
int bfs() 
{
    q.push({ a - 1, k });                       // 起点a-1，最多允许k次跳跃
    path[a - 1] = 1;                            // 标记起点已访问

    // 广度优先搜索遍历
    while (!q.empty()) 
    {
        int cur = q.front().first;              // 当前节点
        int nk = q.front().second;              // 剩余可跳跃次数
        q.pop();                                // 弹出队头元素

        // 如果当前节点是终点，返回路径长度
        if (cur == b - 1) 
        {
            return path[cur] - 1;               // 需要减1因为路径长度包括起点
        }

        // 1. 跳跃x步
        int next1 = (x + cur) % n;              // 计算移动 x 时，下一个节点的位置，取模n防止越界
        if (path[next1] == 0) 
        {
            path[next1] = path[cur] + 1;        // 更新路径长度
            q.push({ next1, nk });              // 将新节点加入队列
        }

        // 2. 跳跃y步
        int next2 = (cur - y + n) % n;          // 计算移动 y 时，下一个节点的位置，取模n防止越界
        if (path[next2] == 0) 
        {
            path[next2] = path[cur] + 1;        // 更新路径长度
            q.push({ next2, nk });              // 将新节点加入队列
        }

        // 3. 如果还有剩余发动技能次数，跳跃n/2步
        if (nk > 0) 
        {
            int next3 = (cur + n / 2) % n;      // 计算发动技能 n/2 时，下一个节点的位置，取模n防止越界
            if (path[next3] == 0) 
            {
                path[next3] = path[cur] + 1;    // 更新路径长度
                q.push({ next3, nk - 1 });      // 将新节点加入队列，跳跃次数减少
            }
        }
    }

    return -1;                                  // 如果无法到达终点，返回-1
}

int main() 
{
    cin >> n >> k >> a >> b >> x >> y;          // 输入：节点数n，最大跳跃次数k，起点a，终点b，步长x，步长y
    cout << bfs();                              // 输出结果
    return 0;
}