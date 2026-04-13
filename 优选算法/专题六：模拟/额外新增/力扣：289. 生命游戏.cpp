// 力扣：289. 生命游戏
// 链接：https://leetcode.cn/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：暴力模拟
class Solution
{
public:
    int check(vector<vector<int>>& temp, int i, int j)
    {
        int x = temp.size(), y = temp[0].size();
        int sum = 0;

        if (i - 1 >= 0 && j - 1 >= 0)
        {
            sum += temp[i - 1][j - 1];
        }

        if (i - 1 >= 0)
        {
            sum += temp[i - 1][j];
        }

        if (i - 1 >= 0 && j + 1 < y)
        {
            sum += temp[i - 1][j + 1];
        }

        if (j - 1 >= 0)
        {
            sum += temp[i][j - 1];
        }

        if (j + 1 < y)
        {
            sum += temp[i][j + 1];
        }

        if (i + 1 < x && j - 1 >= 0)
        {
            sum += temp[i + 1][j - 1];
        }

        if (i + 1 < x)
        {
            sum += temp[i + 1][j];
        }

        if (i + 1 < x && j + 1 < y)
        {
            sum += temp[i + 1][j + 1];
        }

        return sum;
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        vector<vector<int>> temp = board;
        for (int i = 0; i < temp.size(); i++)
        {
            for (int j = 0; j < temp[0].size(); j++)
            {
                if (temp[i][j] == 1 && (check(temp, i, j) < 2 || check(temp, i, j) > 3))
                {
                    board[i][j] = 0;
                }

                if (temp[i][j] == 0 && (check(temp, i, j) == 3))
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};






// 方法二：原地操作（状态位）
// 活变死记成 2（原来是1），死变活记成 3（原来是0）
// 统计周围活细胞时，只要看到 1 或者 2，都算活的
// 最后遍历一遍，把 2 改回 0，3 改回 1 
class Solution
{
public:
    int check(vector<vector<int>>& board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        int sum = 0;

        // 遍历上下左右8个方向
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if (x == 0 && y == 0)
                {
                    continue; // 跳过自己
                }

                int ni = i + x;
                int nj = j + y;

                // 检查边界
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    // 1是本来活的，2是活变死的，这俩都算活细胞
                    if (board[ni][nj] == 1 || board[ni][nj] == 2)
                    {
                        sum++;
                    }
                }
            }
        }

        return sum;
    }

    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();

        // 1.根据规则打标记
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1 && (check(board, i, j) < 2 || check(board, i, j) > 3))
                {
                    board[i][j] = 2;
                }

                if (board[i][j] == 0 && (check(board, i, j) == 3))
                {
                    board[i][j] = 3;
                }
            }
        }

        // 2.把标记还原成最终结果
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 2)
                {
                    board[i][j] = 0; // 活变死
                }
                else if (board[i][j] == 3)
                {
                    board[i][j] = 1; // 死变活
                }
            }
        }
    }
};