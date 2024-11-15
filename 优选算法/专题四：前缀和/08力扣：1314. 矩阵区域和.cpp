//力扣：1314. 矩阵区域和
//https://leetcode.cn/problems/matrix-block-sum/description/


//方法一：暴力法
//时间复杂度：O(mn^2)
//暴力法解题思路
//1. 遍历矩阵每个元素：对于每个位置(i, j)，计算其在 k×k 范围内的和。
//2. 累加元素和：
//    · sum 用于存储当前位置周围 k×k 范围内的所有元素的和。
//    · 范围控制：通过 max 和 min 函数来保证循环不越界，分别确定范围的上下界 r 和 c。
//3. 存储结果：将累计和 sum 存入 ret[i][j]。
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int m = mat.size();                       // 行数
        int n = mat[0].size();                    // 列数
        vector<vector<int>> ret(m, vector<int>(n, 0));   // 结果矩阵初始化

        // 暴力计算每个元素的 k 范围内的和
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;                      // 用于累计 k 范围内的和

                // 遍历当前元素的 k 范围
                for (int r = max(0, i - k); r <= min(m - 1, i + k); r++)
                {
                    for (int c = max(0, j - k); c <= min(n - 1, j + k); c++)
                    {
                        sum += mat[r][c];         // 累加范围内的每个元素
                    }
                }

                ret[i][j] = sum;                  // 将结果存入 ret 矩阵
            }
        }

        return ret;
    }
};





//方法二：二维前缀和
//时间复杂度：O(mn)

//算法原理：
//⼆维前缀和的简单应⽤题，关键就是我们在填写结果矩阵的时候，要找到原矩阵对应区域的「左上⻆」以及「右下⻆」的坐标（推荐⼤家画图）
//左上⻆坐标： x1 = i - k，y1 = j - k ，但是由于会「超过矩阵」的范围，因此需要对 0取⼀个 max 。因此修正后的坐标为： x1 = max(0, i - k), y1 = max(0, j - k);
//右下⻆坐标： x1 = i + k，y1 = j + k ，但是由于会「超过矩阵」的范围，因此需要对 m- 1 ，以及 n - 1 取⼀个 min 。因此修正后的坐标为： x2 = min(m - 1, i + k),y2 = min(n - 1, j + k) 。
//然后将求出来的坐标代⼊到「⼆维前缀和矩阵」的计算公式上即可~（但是要注意下标的映射关系）
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int m = mat.size();                      // 矩阵行数
        int n = mat[0].size();                   // 矩阵列数
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));   // 前缀和矩阵，扩展一行和一列以简化边界处理

        // 构建二维前缀和矩阵
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
                //          上方区域和     左方区域和     减去重复的左上区域      加上当前元素
            }
        }

        vector<vector<int>> ret(m, vector<int>(n));    // 结果矩阵

        // 计算每个元素的 k 范围内的和
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;           // 计算左上角坐标
                int x2 = min(m - 1, i + k) + 1, y2 = min(n - 1, j + k) + 1;   // 计算右下角坐标

                // 使用前缀和快速计算子矩阵和
                ret[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
                //          右下角区域和 去除上方多余区域  去除左方多余区域   加回左上角重叠区域
            }
        }

        return ret;
    }
};
//核心公式：
//dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
//这个公式利用了前缀和的性质，通过减去多余的上方和左方区域，再加回左上角重叠区域，得到指定范围的和。