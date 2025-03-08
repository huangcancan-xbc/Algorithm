// 力扣：733. 图像渲染
// 链接：https://leetcode.cn/problems/flood-fill/description/


//方法：Flood Fill算法

//算法原理：
//可以利⽤「深搜」或者「宽搜」，遍历到与该点相连的所有「像素相同的点」，然后将其修改成指定的像素即可。
class Solution
{
public:
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int n, m;
    int temp;

    void dfs(vector<vector<int>>& image, int i, int j, int color)
    {
        image[i][j] = color;                    // 修改当前点的颜色

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];

            // 判断当前点是否在图像范围内，且颜色与当前点相同
            if (x >= 0 && x < n && y >= 0 && y < m && image[x][y] == temp)
            {
                dfs(image, x, y, color);        // 递归修改相邻点的颜色
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        n = image.size(), m = image[0].size();
        temp = image[sr][sc];                   // 记录当前点的颜色

        if (image[sr][sc] == color)
        {
            return image;                       // 若当前点颜色与目标颜色相同，则直接返回
        }

        dfs(image, sr, sc, color);

        return image;
    }
};