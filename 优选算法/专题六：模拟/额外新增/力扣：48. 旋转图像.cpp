// 力扣：48. 旋转图像
// 链接：https://leetcode.cn/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：模拟 + 找规律
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        // 先沿对角线翻转
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i != j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // 在水平翻转
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};




// 方法二：数学模拟定位
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[j][n - 1 - i] = matrix[i][j];  // 直接算出目标位置
            }
        }

        matrix = temp;
    }
};