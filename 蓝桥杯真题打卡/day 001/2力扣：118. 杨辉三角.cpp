//力扣：118. 杨辉三角
//链接：https://leetcode.cn/problems/pascals-triangle/description/


//方法：模拟
class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> v(numRows);

        // 第一步：初始化每一行的首尾元素为 1
        for (int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);                                 // 调整当前行的大小为 i + 1
            v[i][0] = v[i][v[i].size() - 1] = 1;                // 设置当前行的第一个和最后一个元素为 1
            // 或者：v[i][0] = v[i][i] = 1;
        }

        // 第二步：计算每一行的中间元素
        for (int i = 2; i < numRows; i++)                       // 从第 3 行开始计算（索引 2）
        {
            for (int j = 1; j < i; j++)                         // 跳过首尾元素
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];        // 中间元素为上一行相邻两个元素之和
            }
        }

        return v;
    }
};
/*
代码说明：
1. 主体思路基于“杨辉三角”的特性：
   - 每行首尾元素固定为 1。
   - 中间元素为上一行相邻元素之和。

2. 使用双重 for 循环：
   - 外层循环控制行数（rows），初始化每一行。
   - 内层循环填充每一行的中间元素。

3. 复杂度分析：
   - 时间复杂度：O(numRows^2)，因为需要计算每一行的每个元素。
   - 空间复杂度：O(numRows^2)，用于存储整个三角形。

关键点 (Key Points):
1. `resize` 方法：调整 vector 的大小以适应当前行的元素个数。
2. 直接赋值首尾元素：`v[i][0]` 和 `v[i][i]`。
3. 计算中间元素：`v[i][j] = v[i-1][j-1] + v[i-1][j]`，反映了杨辉三角的递推关系。
*/