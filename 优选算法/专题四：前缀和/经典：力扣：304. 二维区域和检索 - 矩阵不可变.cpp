// 力扣：304. 二维区域和检索 - 矩阵不可变
// 链接：https://leetcode.cn/problems/range-sum-query-2d-immutable/description/

// 方法：前缀和
// 注意点：为矩阵增添一行一列要注意下标的映射！！
class NumMatrix
{
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        sum.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */