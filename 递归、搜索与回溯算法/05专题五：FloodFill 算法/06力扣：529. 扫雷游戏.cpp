// 力扣：529. 扫雷游戏
// 链接：https://leetcode.cn/problems/minesweeper/description/


//方法：Flood Fill算法

//算法原理：模拟类型的 dfs 题⽬。
//⾸先要搞懂题⽬要求，也就是游戏规则。从题⽬所给的点击位置开始，根据游戏规则，来⼀次 dfs 即可。
class Solution
{
public:
    int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int n, m;

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int count = 0;

        // 检查周围8个方向的地雷数
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 判断是否在边界内，并且是否为地雷
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'M')
            {
                count++;                    // 如果是地雷，计数++
            }
        }

        if (count)
        {
            board[i][j] = count + '0';      // 如果周围有地雷，则更新当前位置的数字, 并返回
            return;
        }
        else
        {
            board[i][j] = 'B';              // 如果周围没有地雷，则标记为'B'（空白区域）
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k], y = j + dy[k];

                // 判断是否在边界内并且是空白区域
                if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == 'E')
                {
                    dfs(board, x, y);
                }
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        n = board.size(), m = board[0].size();

        int x = click[0], y = click[1];     // 记录点击的位置

        // 如果点击的是地雷，直接标记为'X', 并返回
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        dfs(board, x, y);

        return board;
    }
};