//04力扣：130. 被围绕的区域
//https://leetcode.cn/problems/surrounded-regions/description/


//方法：BFS
//算法原理：正难则反。
//可以先利⽤ bfs 将与边缘相连的 '0' 区域做上标记，然后重新遍历矩阵，将没有标记过的 '0' 修改成 'X' 即可。
class Solution 
{
public:
    typedef pair<int, int> pii;
    int dx[4] = { 0, 0, 1, -1 };                                // 方向向量，分别表示右、左、下、上
    int dy[4] = { 1, -1, 0, 0 };
    int row, column;

    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<pii> q;
        q.push({ i, j });
        board[i][j] = '.';                                      // 标记为已访问

        while (q.size())                                        // 队列非空时继续
        {
            auto [a, b] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)                         // 遍历四个方向
            {
                int x = a + dx[k], y = b + dy[k];
                if (x >= 0 && x < row && y >= 0 && y < column && board[x][y] == 'O')
                {
                    q.push({ x, y });                           // 加入队列
                    board[x][y] = '.';                          // 标记为已访问
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        row = board.size();

        if (row == 0)
        {
            return;                                             // 特殊情况处理
        }

        column = board[0].size();

        // 遍历上下边界
        for (int i = 0; i < column; i++)
        {
            if (board[0][i] == 'O')                             // 第一行
            {
                bfs(board, 0, i);
            }

            if (board[row - 1][i] == 'O')                       // 最后一行
            {
                bfs(board, row - 1, i);
            }
        }

        // 遍历左右边界
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')                             // 第一列
            {
                bfs(board, i, 0);
            }

            if (board[i][column - 1] == 'O')                    // 最后一列
            {
                bfs(board, i, column - 1);
            }
        }

        // 修改矩阵
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';                          // 未被标记的 'O' 替换为 'X'
                }
                else if (board[i][j] == '.')
                {
                    board[i][j] = 'O';                          // 标记的 '.' 还原为 'O'
                }
            }
        }
    }
};
