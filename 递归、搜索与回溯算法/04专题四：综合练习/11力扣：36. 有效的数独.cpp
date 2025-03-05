//力扣：36. 有效的数独
//链接：https://leetcode.cn/problems/valid-sudoku/description/


//方法：有点像哈希表，但是又和*N皇后*相似，所以放到这里
//算法原理：创建三个数组标记⾏、列以及 3 * 3 ⼩⽅格中是否出现 1~9 之间的数字即可。
class Solution
{
public:
    bool row[9][10];                        // row[i][num] 表示第 i 行是否出现过数字 num
    bool column[10][9];                     // column[j][num] 表示第 j 列是否出现过数字 num
    bool grid[3][3][10];                    // grid[x][y][num] 表示 (x, y) 小方格是否出现过数字 num

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')     // 如果当前单元格不为空
                {
                    int temp = board[i][j] - '0';// 将字符转换为数字

                    // 检查当前数字是否在对应的行、列或小方格中已经存在
                    if (row[i][temp] || column[temp][j] || grid[i / 3][j / 3][temp])
                    {
                        return false;       // 若冲突，直接返回 false
                    }

                    // 标记当前数字已在对应的行、列和小方格中出现
                    row[i][temp] = column[temp][j] = grid[i / 3][j / 3][temp] = true;
                }
            }
        }

        return true;
    }
};