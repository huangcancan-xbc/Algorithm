// 力扣：LCR 130. 衣橱整理 （原：面试题 13. 机器人的运动范围 ）
// 链接：https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/


//方法：Flood Fill算法

//算法原理：这是⼀道⾮常典型的「搜索」类问题。
//我们可以通过「深搜」或者「宽搜」，从[0, 0] 点出发，按照题⽬的「规则」⼀直往[m - 1, n - 1] 位置⾛。
//同时，设置⼀个全局变量。每次⾛到⼀个合法位置，就将全局变量加⼀。当我们把所有能⾛到的路都⾛完之后，全局变量⾥⾯存的就是最终答案。
class Solution
{
public:
    int _m, _n, _k;                         // 记录矩阵的行数、列数和限制条件
    int ret;                                // 结果变量，记录符合条件的单元格数量
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int vis[105][105];

    // 检查坐标 (x, y) 是否满足条件：数字各位之和小于等于 k
    bool check(int x, int y)
    {
        int sum = 0;

        // 计算 x 各位数字之和
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }

        // 计算 y 各位数字之和
        while (y)
        {
            sum += y % 10;
            y /= 10;
        }

        return sum <= _k;                   // 如果总和小于等于 k，返回 true
    }

    void dfs(int i, int j)
    {
        ret++;                              // 遇到一个符合条件的单元格，结果加1
        vis[i][j] = true;                   // 标记当前单元格已访问

        // 遍历四个方向
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 判断是否越界，是否已访问，是否符合条件
            if (x >= 0 && x < _n && y >= 0 && y < _m && !vis[x][y] && check(x, y))
            {
                dfs(x, y);                  // 递归调用，继续深度优先搜索
            }
        }
    }

    int wardrobeFinishing(int m, int n, int cnt)
    {
        _m = m, _n = n, _k = cnt;           // 初始化矩阵大小和条件

        dfs(0, 0);                          // 从 (0, 0) 开始进行深度优先搜索

        return ret;                         // 返回结果
    }
};
