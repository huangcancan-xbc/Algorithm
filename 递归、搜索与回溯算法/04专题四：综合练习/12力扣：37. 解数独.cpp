// 力扣：37. 解数独
// 链接：https://leetcode.cn/problems/sudoku-solver/

// 方法：DFS（深度优先搜索）+ 回溯法
// 算法原理：
// 1. 使用三个布尔数组（row、column、grid）分别记录数字在行、列和 3×3 小方格中是否出现过。
// 2. 通过 DFS（深度优先搜索）尝试填充每个空格，当遇到冲突时回溯（撤销操作）。
// 3. 若填充成功，则返回 true；否则，尝试其他可能的数字。

class Solution
{
public:
    // 标记数组：分别记录行、列和小方格中某个数字是否出现过
    bool row[9][10];                                    // row[i][num] 表示第 i 行是否出现过数字 num
    bool column[10][9];                                 // column[j][num] 表示第 j 列是否出现过数字 num
    bool grid[3][3][10];                                // grid[x][y][num] 表示 (x, y) 小方格是否出现过数字 num

    // 深度优先搜索函数，用于填充数独
    bool dfs(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')                 // 如果当前单元格为空
                {
                    for (int num = 1; num <= 9; num++)  // 尝试填充数字 1~9
                    {
                        // 检查数字是否在当前行、列或小方格中出现过
                        if (!row[i][num] && !column[num][j] && !grid[i / 3][j / 3][num])
                        {
                            board[i][j] = num + '0';    // 填充当前数字并标记已使用
                            row[i][num] = column[num][j] = grid[i / 3][j / 3][num] = true;

                            if (dfs(board))
                            {
                                return true;            // 递归尝试填充下一个空格，如果成功完成填充，直接返回 true
                            }

                            board[i][j] = '.';          // 回溯：撤销当前操作
                            row[i][num] = column[num][j] = grid[i / 3][j / 3][num] = false;
                        }
                    }

                    return false;                       // 如果 1~9 都无法填充，则返回 false
                }
            }
        }

        return true;                                    // 全部填充成功
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        // 初始化标记数组，根据初始的数独板更新状态
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')                 // 若单元格不为空
                {
                    int temp = board[i][j] - '0';       // 将字符转换为数字
                    row[i][temp] = column[temp][j] = grid[i / 3][j / 3][temp] = true;
                }
            }
        }

        dfs(board);                                     // 调用 DFS 填充数独
    }
};
