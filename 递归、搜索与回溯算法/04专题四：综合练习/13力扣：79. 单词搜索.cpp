// 力扣：79. 单词搜索
// 链接：https://leetcode.cn/problems/word-search/

// 方法：DFS（深度优先搜索）+ 回溯法
// 算法原理：
// 1. 使用 DFS 搜索单词路径，每次匹配一个字符，沿四个方向继续搜索下一个字符。
// 2. 使用布尔数组 `vis` 记录单元格是否已访问，避免重复使用。
// 3. 若搜索路径失败，则回溯（撤销当前操作），尝试其他方向。

//递归函数流程：
//1. 遍历每个位置，标记当前位置并将当前位置的字⺟作为⾸字⺟进⾏递归，并且在回溯时撤回标记。
//2. 在每个递归的状态中，我们维护⼀个步数 step，表⽰当前已经处理了⼏个字⺟。
//    ◦ 若当前位置的字⺟与字符串中的第 step 个字⺟不相等，则返回 false。
//    ◦ 若当前 step 的值与字符串⻓度相等，表⽰存在⼀种路径使得 word 成⽴，返回 true。
//3. 对当前位置的上下左右四个相邻位置进⾏递归，若递归结果为 true，则返回 true。
//4. 若相邻的四个位置的递归结果都为 false，则返回 false。
//• 特别地，如果使⽤将当前遍历到的字符赋值为空格，并在回溯时恢复为原来的字⺟的⽅法，则在递归时不会重复遍历当前元素，可达到不使⽤标记数组的⽬的。
class Solution
{
public:
    bool vis[7][7] = { false };              // 访问标记数组，记录某个单元格是否已被访问
    int n, m;                                // n 表示行数，m 表示列数
    int dx[4] = { 0, 0, 1, -1 };             // 四个方向的横坐标变化（右、左、下、上）
    int dy[4] = { 1, -1, 0, 0 };             // 四个方向的纵坐标变化（右、左、下、上）

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos)
    {
        if (pos == word.size())              // 如果当前匹配位置等于单词长度，说明单词已全部匹配成功
        {
            return true;
        }

        for (int k = 0; k < 4; k++)          // 遍历四个方向
        {
            int x = i + dx[k];               // 计算下一个单元格的横坐标
            int y = j + dy[k];               // 计算下一个单元格的纵坐标

            // 检查下一个单元格是否在边界内、字符是否匹配、是否未被访问
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == word[pos] && !vis[x][y])
            {
                vis[x][y] = true;            // 标记当前单元格为已访问

                if (dfs(board, x, y, word, pos + 1))
                {
                    return true;             // 递归搜索下一个字符，如果找到匹配路径，返回 true
                }

                vis[x][y] = false;           // 回溯：撤销当前单元格的访问状态
            }
        }

        return false;                        // 如果四个方向都无法找到匹配路径，返回 false
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        n = board.size();                    // 获取网格的行数
        m = board[0].size();                 // 获取网格的列数

        for (int i = 0; i < n; i++)          // 遍历每一个单元格作为起点
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])  // 如果当前单元格字符匹配单词的首字符
                {
                    vis[i][j] = true;        // 标记当前单元格为已访问

                    if (dfs(board, i, j, word, 1)) // 从当前单元格开始搜索单词的剩余部分
                    {
                        return true;         // 如果找到匹配路径，返回 true
                    }

                    vis[i][j] = false;       // 回溯：撤销当前单元格的访问状态
                }
            }
        }

        return false;                       // 如果所有路径都未找到匹配，返回 false
    }
};
