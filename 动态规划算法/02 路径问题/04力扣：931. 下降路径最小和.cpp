// 力扣：931. 下降路径最小和
// 链接：https://leetcode.cn/problems/minimum-falling-path-sum/description/

// 方法：动态规划
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        
        int n = matrix.size();              // 获取矩阵的行数

        // 创建一个 dp 数组，大小为 (n+1) x (n+2)，并初始化为 INT_MAX，dp[i][j] 代表从 matrix[i-1][j-1] 位置到达的最小路径和，额外的行列是为了避免越界访问
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));

        for (int i = 0; i < n + 2; i++)
        {
            dp[0][i] = 0;                   // 初始化 dp 数组的第一行，所有值设为 0，这一步是为了处理边界条件
        }

        for (int i = 1; i <= n; i++)        // 从第二行 (i = 1) 开始填充 dp 数组，直到最后一行 (i = n)
        {
            for (int j = 1; j <= n; j++)    // 遍历当前行的每一列 (j = 1 到 n)
            {
                // 计算当前位置的最小路径和，取上方三种可能的路径：左上、正上、右上
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i - 1][j - 1];
            }
        }

        int ret = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            ret = min(ret, dp[n][i]);       // 在 dp 数组的最后一行中，找到最小的路径和，这一步表示从任意位置到达矩阵最后一行的最小路径和
        }

        return ret;                         // 返回最小路径和
    }
};


// 空间优化：使用一维数组保存上一行的最小路径和，并在更新 dp 数组时，使用临时数组保存当前行的计算结果，最后返回 dp 数组的最小值
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        vector<int> dp(n, INT_MAX);         // 使用一个一维数组来保存上一行的最小路径和

        for (int j = 0; j < n; j++)
        {
            dp[j] = matrix[0][j];           // 初始化 dp 数组为第一行的值
        }

        for (int i = 1; i < n; i++)         // 从第二行开始更新 dp 数组
        {
            vector<int> temp(n, INT_MAX);   // 临时数组保存当前行的计算结果
            for (int j = 0; j < n; j++)
            {
                // 对于每个位置，计算三个可能的路径
                if (j > 0)
                {
                    temp[j] = min(temp[j], dp[j - 1] + matrix[i][j]);   // 左上
                }

                temp[j] = min(temp[j], dp[j] + matrix[i][j]);           // 正上

                if (j < n - 1)
                {
                    temp[j] = min(temp[j], dp[j + 1] + matrix[i][j]);   // 右上
                }
            }
            dp = temp;                      // 更新 dp 为当前行的结果
        }

        return *min_element(dp.begin(), dp.end());                      // 最后遍历 dp 数组，找出最小值
    }
};
