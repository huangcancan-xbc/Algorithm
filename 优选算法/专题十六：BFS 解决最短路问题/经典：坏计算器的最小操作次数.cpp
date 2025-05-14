//坏计算器的最小操作次数
//参考链接：https://www.marscode.cn/practice/ln5qk8794j4nkd?problem_id=7424436653371523116

//问题描述：
//小M有一个坏掉的计算器，它有两种功能可以操作屏幕上显示的数字：
//	· 将显示的数字乘以2；
//	· 将显示的数字减去1。
//现在，计算器上显示的数字是 x，小M希望通过最少的操作次数，将数字变为 y。
//请你帮忙计算一下，最少需要多少次操作才能将数字从 x 变为 y。


//参考：


//方法一：逆向思维反推
#include <iostream>
using namespace std;

// 计算最少操作次数
int minOperations(int x, int y) 
{
    int steps = 0;                              // 操作次数

    // 反向操作从 y 开始
    while (y > x) 
    {
        if (y % 2 == 0) 
        {
            y /= 2;                             // 如果 y 是偶数，则逆向操作为除以 2
        }
        else 
        {
            y += 1;                             // 如果 y 是奇数，则逆向操作为加 1
        }
        steps++;                                // 每次操作计数
    }

    return steps + (x - y);                     // 最后加上 y 到 x 的差值
}

int main() 
{
    int x, y;
    cout << "请输入初始值 x 和目标值 y：";
    cin >> x >> y;

    int result = minOperations(x, y);
    cout << "最少操作次数为：" << result << endl;

    return 0;
}
//为什么需要(x - y)？
//当 y <= x 时，反向操作不足以覆盖所有步数，直接通过加法调整补齐操作。
//举一个简单的例子：
//输入：x = 3, y = 3，应该输出 0，无需任何操作；
//输入：x = 5, y = 2，从 2 逆推到 5 时不能通过反向除法或加法直接抵达，需要补上 5 - 2 = 3。
//如果没有这部分补偿，当反向过程无法完全覆盖到目标（y <= x 时），结果会不正确。




//方法二：BFS 算法
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int BFS(int x, int y) 
{
    queue<pair<int, int>> q;            // 队列，存储数字和对应的操作次数
    unordered_set<int> visited;         // 用于避免重复访问
    q.push({ x, 0 });                   // 初始值入队，操作次数为 0
    visited.insert(x);

    while (!q.empty()) 
    {
        int curr = q.front().first;     // 当前数字
        int steps = q.front().second;   // 当前操作次数
        q.pop();

        if (curr == y) 
        {
            return steps;               // 找到目标，返回操作次数
        }

        // 如果当前数字小于目标值 y，可以尝试乘以2
        if (curr < y && !visited.count(curr * 2)) 
        {
            q.push({ curr * 2, steps + 1 });
            visited.insert(curr * 2);
        }

        // 尝试减去1
        if (curr > 0 && !visited.count(curr - 1)) 
        {
            q.push({ curr - 1, steps + 1 });
            visited.insert(curr - 1);
        }
    }

    return -1;                          // 理论上不会到达这里
}

int main() 
{
    int x, y;
    cout << "请输入初始值 x 和目标值 y：";
    cin >> x >> y;

    int result = BFS(x, y);
    cout << "最少操作次数为：" << result << endl;

    return 0;
}
