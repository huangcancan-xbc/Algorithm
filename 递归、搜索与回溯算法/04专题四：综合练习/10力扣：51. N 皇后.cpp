//力扣：51. N 皇后
//链接：https://leetcode.cn/problems/n-queens/description/


//方法：DFS

//代码一：直接显式的检查四个方向，效率较低
class Solution
{
public:
    vector<vector<string>> ret;                 // 存储所有解决方案
    vector<string> path;                        // 当前棋盘状态
    // check_row[i] 标记行是否被占用, check_column[i] 标记列是否被占用,
    // check_diagonal1[i] 标记主对角线是否被占用, check_diagonal2[i] 标记副对角线是否被占用
    bool check_row[10], check_column[10], check_diagonal1[20], check_diagonal2[20];
    int _n;                                     // 棋盘大小（N）

    void dfs(int row)
    {
        if (row == _n)
        {
            ret.push_back(path);                // 找到一个解决方案，存储当前棋盘, 并返回
            return;
        }

        for (int column = 0; column < _n; column++)
        {
            // 检查行、列、主对角线和副对角线是否已被占用
            if (!check_row[row] && !check_column[column] && !check_diagonal1[row - column + _n] && !check_diagonal2[row + column])
            {
                path[row][column] = 'Q';        // 放置皇后

                // 标记当前行、列和对角线为已占用
                check_row[row] = check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = true;

                dfs(row + 1);

                path[row][column] = '.';        // 撤销放置

                check_row[row] = check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        _n = n;
        //ret.clear();                          // 清空之前的结果
        //path.clear();                         // 清空之前的路径
        path.resize(_n);                        // 初始化路径（棋盘），大小为 n
        for (int i = 0; i < _n; i++)
        {
            path[i].assign(_n, '.');            // 每一行初始化为 n 个 '.'，表示空位
        }

        // 初始化检查数组
        //for (int i = 0; i < _n; i++) 
        //{
        //    check_row[i] = false;
        //    check_column[i] = false;
        //}
        //for (int i = 0; i < 2 * _n; i++)
        //{
        //    check_diagonal1[i] = false;
        //    check_diagonal2[i] = false;
        //}

        dfs(0);                                 // 从第 0 行开始深度优先搜索
        return ret;
    }
};




//代码二：使用层级结构，只检查列、主对角线和副对角线是否被占用，可以不用显式检查行，效率增高

//算法原理：
//⾸先，我们在第⼀⾏放置第⼀个皇后，然后遍历棋盘的第⼆⾏，在可⾏的位置放置第⼆个皇后，然后再遍历第三⾏，
//在可⾏的位置放置第三个皇后，以此类推，直到放置了 n 个皇后为⽌。我们需要⽤⼀个数组来记录每⼀⾏放置的皇后的列数。
//在每⼀⾏中，我们尝试放置⼀个皇后，并检查是否会和前⾯已经放置的皇后冲突。如果没有冲突，我们就继续递归地放置下⼀⾏的皇后，直到所有的皇后都放置完毕，然后把这个⽅案记录下来。
//在检查皇后是否冲突时，我们可以⽤⼀个数组来记录每⼀列是否已经放置了皇后，并检查当前要放置的皇后是否会和已经放置的皇后冲突。
//对于对⻆线，我们可以⽤两个数组来记录从左上⻆到右下⻆的每⼀条对⻆线上是否已经放置了皇后，以及从右上⻆到左下⻆的每⼀条对⻆线上是否已经放置了皇后。
//
//• 对于对⻆线是否冲突的判断可以通过以下流程解决：
//1. 从左上到右下：相同对⻆线的⾏列之差相同；
//2. 从右上到左下：相同对⻆线的⾏列之和相同。
//
//因此，我们需要创建⽤于存储解决⽅案的⼆维字符串数组 solutions ，⽤于存储每个皇后的位置的⼀维整数数组 queens ，
//以及⽤于记录每⼀列和对⻆线上是否已经有皇后的布尔型数组columns 、 diagonals1 和 diagonals2 。
//
//递归函数流程如下：
//1. 结束条件：如果 row 等于 n ，则表⽰已经找到⼀组解决⽅案，此时将每个皇后的位置存储到字符串数组 board 中，并将 board 存储到 solutions 数组中，然后返回；
//2. 枚举当前⾏的每⼀列，判断该列、两个对⻆线上是否已经有皇后：
//    a.如果有皇后，则继续枚举下⼀列；
//    b.否则，在该位置放置皇后，并将 columns 、 diagonals1 和 diagonals2 对应的位置
//设为 true ，表⽰该列和对⻆线上已经有皇后：
//递归调⽤ dfs 函数，搜索下⼀⾏的皇后位置。如果该⽅案递归结束，则在回溯时需要将columns 、 diagonals1 和 diagonals2 对应的位置设为 false ，然后继续枚举下⼀列；
class Solution
{
public:
    vector<vector<string>> ret;                 // 存储所有解决方案
    vector<string> path;                        // 当前棋盘状态
    // check_column[i] 标记列是否被占用, check_diagonal1[i] 标记主对角线是否被占用, check_diagonal2[i] 标记副对角线是否被占用
    bool check_column[10], check_diagonal1[20], check_diagonal2[20];
    int _n;                                     // 棋盘大小（N）

    void dfs(int row)
    {
        if (row == _n)
        {
            ret.push_back(path);                // 找到一个解决方案，存储当前棋盘, 并返回
            return;
        }

        for (int column = 0; column < _n; column++)
        {
            // 检查列、主对角线和副对角线是否已被占用
            if (!check_column[column] && !check_diagonal1[row - column + _n] && !check_diagonal2[row + column])
            {
                path[row][column] = 'Q';        // 放置皇后
                check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = true;

                dfs(row + 1);                   // 递归到下一行

                path[row][column] = '.';        // 撤销放置
                check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        _n = n;
        path.resize(_n);                        // 初始化路径（棋盘），大小为 n
        for (int i = 0; i < _n; i++)
        {
            path[i].append(_n, '.');            // 每一行初始化为 n 个 '.'，表示空位
        }

        dfs(0);                                 // 从第 0 行开始深度优先搜索
        return ret;
    }
};



//使用 vector<bool> 替换 bool 数组：
class Solution
{
public:
    vector<vector<string>> ret;                 // 存储所有解决方案
    vector<string> path;                        // 当前棋盘状态
    vector<bool> check_column;                  // 标记列是否被占用
    vector<bool> check_diagonal1;               // 标记主对角线是否被占用
    vector<bool> check_diagonal2;               // 标记副对角线是否被占用
    int _n;                                     // 棋盘大小（N）

    void dfs(int row)
    {
        if (row == _n)
        {
            ret.push_back(path);                // 找到一个解决方案，存储当前棋盘, 并返回
            return;
        }

        for (int column = 0; column < _n; column++)
        {
            // 检查列、主对角线和副对角线是否已被占用
            if (!check_column[column] && !check_diagonal1[row - column + _n] && !check_diagonal2[row + column])
            {
                path[row][column] = 'Q';        // 放置皇后
                check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = true;

                dfs(row + 1);                   // 递归到下一行

                path[row][column] = '.';        // 撤销放置
                check_column[column] = check_diagonal1[row - column + _n] = check_diagonal2[row + column] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        _n = n;
        path.resize(_n);                        // 初始化路径（棋盘），大小为 n
        for (int i = 0; i < _n; i++)
        {
            path[i].append(_n, '.');            // 每一行初始化为 n 个 '.'，表示空位
        }

        // 初始化布尔向量，大小和原先数组一致
        check_column.resize(_n, false);         // 列检查器，大小为 n
        check_diagonal1.resize(2 * _n, false);  // 主对角线检查器，大小为 2 * n
        check_diagonal2.resize(2 * _n, false);  // 副对角线检查器，大小为 2 * n

        dfs(0);                                 // 从第 0 行开始深度优先搜索
        return ret;
    }
};
