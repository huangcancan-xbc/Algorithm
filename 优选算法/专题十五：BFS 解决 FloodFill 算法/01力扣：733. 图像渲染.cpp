//力扣：733. 图像渲染
//https://leetcode.cn/problems/flood-fill/description/


//方法：BFS
//时间复杂度：O(m*n)

//算法原理：
//可以利⽤「深搜」或者「宽搜」，遍历到与该点相连的所有「像素相同的点」，然后将其修改成指定的像素即可。
class Solution {
public:
    typedef pair<int, int> pii;                     // 定义一个二元组类型，表示坐标
    int dx[4] = { 0, 0, 1, -1 };                    // dx数组表示四个方向的横向移动
    int dy[4] = { 1, -1, 0, 0 };                    // dy数组表示四个方向的纵向移动

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];                   // 记录初始点的颜色
        if (prev == color)                          // 如果初始颜色和目标颜色相同，直接返回原图
        {
            return image;
        }

        int m = image.size();                       // 图像的行数
        int n = image[0].size();                    // 图像的列数

        queue<pii> q;                               // 定义队列用于BFS
        q.push({ sr, sc });                         // 将起点入队

        while (!q.empty())                          // BFS循环直到队列为空
        {
            auto [a, b] = q.front();                // 取出队首元素，当前处理的坐标
            q.pop();                                // 从队列中移除队首元素

            image[a][b] = color;                    // 将当前点染成目标颜色

            for (int i = 0; i < 4; i++)             // 遍历四个方向
            {
                int x = a + dx[i];                  // 计算新横坐标
                int y = b + dy[i];                  // 计算新纵坐标

                // 判断新坐标是否在图像范围内，且颜色与初始颜色相同
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == prev)
                {
                    q.push({ x, y });               // 将符合条件的坐标入队
                }
            }
        }

        return image;                               // 返回修改后的图像
    }
};