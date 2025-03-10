// 力扣：130. 被围绕的区域
// 链接：https://leetcode.cn/problems/surrounded-regions/description/


// 方法：Flood Fill算法

//算法原理：正难则反。
//可以先利⽤ dfs 将与边缘相连的 '0' 区域做上标记，然后重新遍历矩阵，将没有标记过的 '0' 修改成 'X' 即可。
class Solution
{
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int row, column;

    // 深度优先搜索（DFS），将与边缘连接的 'O' 标记为 '.'
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = '.';                      // 标记当前 'O' 为临时标记 '.'
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 如果新位置在棋盘内且是 'O'，递归调用 dfs
            if (x >= 0 && x < row && y >= 0 && y < column && board[x][y] == 'O')
            {
                dfs(board, x, y);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        row = board.size(), column = board[0].size();

        // 将最左列和最右列的 'O' 标记为 '.'
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }

            if (board[i][column - 1] == 'O')
            {
                dfs(board, i, column - 1);
            }
        }

        // 将最上行和最下行的 'O' 标记为 '.'
        for (int j = 0; j < column; j++)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }

            if (board[row - 1][j] == 'O')
            {
                dfs(board, row - 1, j);
            }
        }

        // 遍历整个棋盘，替换剩下的 'O' 为 'X'，并将标记的 '.' 替换回 'O'
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i][j] == '.')         // 连接边缘的 'O'，恢复为 'O'
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')    // 被围住的 'O'，替换为 'X'
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};