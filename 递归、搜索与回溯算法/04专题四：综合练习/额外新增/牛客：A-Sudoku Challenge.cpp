// 牛客：A-Sudoku Challenge
// 链接：https://ac.nowcoder.com/acm/contest/105851/A
// 和力扣：37. 解数独 https://leetcode.cn/problems/sudoku-solver/description/一模一样

// 方法：深度优先搜索
#include <iostream>
#include <vector>
using namespace std;

bool row[9][10];                        // row[i][num] 表示第 i 行是否出现过数字 num
bool column[10][9];                     // column[j][num] 表示第 j 列是否出现过数字 num
bool grid[3][3][10];                    // grid[x][y][num] 表示 (x, y) 小方格是否出现过数字 num 

bool dfs(vector<vector<int>>& board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)                           // 如果当前位置为空
            {
                for (int num = 1; num <= 9; num++)          // 尝试填充数字 1 到 9
                {
                    // 检查数字是否在当前行、列或小方格中出现过
                    if (!row[i][num] && !column[num][j] && !grid[i / 3][j / 3][num])
                    {
                        board[i][j] = num;                  // 填充当前数字并标记已使用
                        row[i][num] = column[num][j] = grid[i / 3][j / 3][num] = true;

                        if (dfs(board) == true)
                        {
                            return true;                    // 递归尝试填充下一个空格，如果成功完成填充，直接返回 true
                        }

                        board[i][j] = 0;                    // 回溯：撤销当前操作
                        row[i][num] = column[num][j] = grid[i / 3][j / 3][num] = false;
                    }
                }

                return false;                               // 如果 1~9 都无法填充，则返回 false
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& board)
{
    // 初始化标记数组，根据初始的数独板更新状态
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)                           // 若单元格不为空
            {
                int temp = board[i][j];                     // 记录当前数字
                row[i][temp] = column[temp][j] = grid[i / 3][j / 3][temp] = true;
            }
        }
    }

    dfs(board);                                             // 调用 DFS 填充数独
}


int main()
{
    vector<vector<int>> board(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}