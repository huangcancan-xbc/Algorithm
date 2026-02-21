// 力扣：54. 螺旋矩阵
// 链接：https://leetcode.cn/problems/spiral-matrix/description/

// 方法：模拟
//定义四个边界：top（上）、bottom（下）、left（左）、right（右）
//按顺序走四步：
//从左→右 走顶行，走完 top++（上边界下移）
//从上→下 走右列，走完 right--（右边界左移）
//从右→左 走底行，走完 bottom--（下边界上移）
//从下→上 走左列，走完 left++（左边界右移）
//每走完一步检查边界是否交叉（top > bottom 或 left > right），交叉了就停
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ret;
        if (matrix.empty())
        {
            return ret;
        }

        // “全局变量”一直更新
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, buttom = matrix.size() - 1;

        while (true)
        {
            // 左到右
            for (int i = left; i <= right; i++)
            {
                ret.push_back(matrix[top][i]);
            }
            if (++top > buttom)  // 走完，上边界下移
            {
                break;
            }

            // 上到下
            for (int i = top; i <= buttom; i++)
            {
                ret.push_back(matrix[i][right]);
            }
            if (--right < left)  // 走完，右边界左移
            {
                break;
            }

            // 右到左
            for (int i = right; i >= left; i--)
            {
                ret.push_back(matrix[buttom][i]);
            }
            if (--buttom < top)    // 走完，下边界上移
            {
                break;
            }

            // 下到上
            for (int i = buttom; i >= top; i--)
            {
                ret.push_back(matrix[i][left]);
            }
            if (++left > right)    // 走完，左边界右移
            {
                break;
            }
        }

        return ret;
    }
};