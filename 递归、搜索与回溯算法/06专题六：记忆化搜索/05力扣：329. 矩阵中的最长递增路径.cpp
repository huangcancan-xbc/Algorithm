// 力扣：329. 矩阵中的最长递增路径
// 链接：https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/


//方法一：递归
class Solution
{
public:
    int n, m;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        int ret = 1;                                // 最短路径长度为 1（只包含自身）

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 检查边界条件和递增关系
            if (x >= 0 && x < n && y >= 0 && y<m && matrix[x][y]>matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);      // 递归求解最长路径
            }
        }

        return ret;                                 // 返回最长路径长度
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        n = matrix.size(), m = matrix[0].size();
        int ret = 0;                                // 保存结果

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dfs(matrix, i, j));  // 更新结果
            }
        }

        return ret;
    }
};



//方法二：记忆化搜索
class Solution
{
public:
    int n, m;
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int memo[201][201];                             // 记忆化数组

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != 0)
        {
            return memo[i][j];                      // 如果已经计算过，直接返回
        }
        int ret = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y<m && matrix[x][y]>matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);
            }
        }
        memo[i][j] = ret;                           // 记录结果到记忆化数组
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        n = matrix.size(), m = matrix[0].size();
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dfs(matrix, i, j));
            }
        }

        return ret;
    }
};

class Solution
{
public:
    int n, m;
    int dx[4] = { 0, 0, 1, -1 };                // 四个方向：右、左、下、上
    int dy[4] = { 1, -1, 0, 0 };

    vector<vector<int>> memo;                   // 记忆化矩阵

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != 0)  
        {
            return memo[i][j];                  // 如果已经计算过，直接返回
        }

        int ret = 1;                            // 最短路径长度为 1（只包含自身）

        // 遍历四个方向
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 检查边界条件和递增关系
            if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j])
            {
                ret = max(ret, dfs(matrix, x, y) + 1);      // 递归求解最长路径
            }
        }

        memo[i][j] = ret;                       // 记录结果到记忆化数组
        return ret;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        n = matrix.size();
        m = matrix[0].size();

        memo = vector<vector<int>>(n, vector<int>(m, 0));  // 初始化记忆化数组为 0

        int ret = 0;                            // 保存结果

        // 遍历矩阵中的每个位置
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dfs(matrix, i, j));          // 更新结果
            }
        }

        return ret;
    }
};



//方法三：动态规划
class Solution 
{
public:
    int n, m;
    int dx[4] = { 0, 0, 1, -1 };                        // 四个方向：右、左、下、上
    int dy[4] = { 1, -1, 0, 0 };

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        n = matrix.size();
        m = matrix[0].size();

        if (n == 0 || m == 0)
        {
            return 0;                                   // 边界检查
        }

        vector<vector<int>> dp(n, vector<int>(m, 1));   // 动态规划数组，初始化为1

        // 创建一个所有元素值的vector，按照值排序
        vector<pair<int, pair<int, int>>> val;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                val.push_back({ matrix[i][j], {i, j} });// 按照值和位置排序
            }
        }

        sort(val.begin(), val.end());                   // 按值升序排序

        // 按照从小到大的顺序更新每个位置的最长路径
        for (auto& val : val) 
        {
            int x = val.second.first;
            int y = val.second.second;

            // 对每个位置，检查它的四个邻居
            for (int k = 0; k < 4; k++) 
            {
                int nx = x + dx[k], ny = y + dy[k];

                // 确保新位置在边界内并且矩阵值递增
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[x][y]) 
                {
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);  // 更新邻居的路径长度
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dp[i][j]);               // 结果为dp数组中的最大值
            }
        }

        return ret;
    }
};