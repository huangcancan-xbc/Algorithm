// 力扣：417. 太平洋大西洋水流问题
// 链接：https://leetcode.cn/problems/pacific-atlantic-water-flow/description/


//方法：Flood Fill算法

//算法原理：正难则反。
//如果直接去判断某⼀个位置是否既能到⼤西洋也能到太平洋，会重复遍历很多路径。
//我们反着来，从⼤西洋沿岸开始反向 dfs ，这样就能找出那些点可以流向⼤西洋；
//同理，从太平洋沿岸也反向 dfs ，这样就能找出那些点可以流向太平洋。那么，被标记两次的点，就是我们要找的结果。

class Solution
{
public:
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int n, m;

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;                                    // 标记当前位置已经被访问
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 检查新位置是否在边界内且未被访问，并且当前位置的高度 <= 新位置的高度
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && heights[x][y] >= heights[i][j])
            {
                dfs(heights, x, y, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        n = heights.size(), m = heights[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m));      // 太平洋的访问标记
        vector<vector<bool>> vis2(n, vector<bool>(m));      // 大西洋的访问标记

        // 从太平洋边界出发
        for (int i = 0; i < n; i++)
        {
            dfs(heights, i, 0, vis1);                       // 左边界
        }
        for (int j = 0; j < m; j++)
        {
            dfs(heights, 0, j, vis1);                       // 上边界
        }

        // 从大西洋边界出发
        for (int i = 0; i < n; i++)
        {
            dfs(heights, i, m - 1, vis2);                   // 右边界
        }
        for (int j = 0; j < m; j++)
        {
            dfs(heights, n - 1, j, vis2);                   // 下边界
        }

        vector<vector<int>> ret;

        // 遍历所有坐标，找到同时能流向太平洋和大西洋的坐标
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis1[i][j] && vis2[i][j])
                {
                    ret.push_back({ i,j });                 // 如果两个位置都是 true,就说明能同时流向太平洋和大西洋，就把这个坐标加入结果
                }
            }
        }

        return ret;
    }
};