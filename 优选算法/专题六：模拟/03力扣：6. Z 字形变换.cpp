//力扣：6. Z 字形变换
//https://leetcode.cn/problems/zigzag-conversion/description/


//方法一：二维矩阵模拟
//时间复杂度：O(n)
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length(), row = numRows;

        // 如果行数为 1 或行数大于等于字符串长度，直接返回字符串
        if (row == 1 || row >= n)
        {
            return s;
        }

        // cycle 表示一个周期的长度，包含向下和向右上两个方向的字符数
        int cycle = row * 2 - 2;

        // 计算列数 column，列数通过周期长度 cycle 和字符串长度 n 来计算
        int column = (n + cycle - 1) / cycle * (row - 1);

        // 创建二维矩阵 mat 来保存 Z 字形排列的字符
        vector<string> mat(row, string(column, 0));

        // 填充矩阵
        for (int i = 0, x = 0, y = 0; i < n; ++i)
        {
            mat[x][y] = s[i];               // 将字符 s[i] 放入矩阵中的位置 (x, y)

            if (i % cycle < row - 1)        // 判断是否向下移动
            {
                ++x;                        // 向下移动
            }
            else
            {
                --x;
                ++y;                        // 向右上移动
            }
        }

        // 将矩阵中的非空字符按行读取，组成答案字符串
        string ans;
        for (auto& row : mat)
        {
            for (char ch : row)
            {
                if (ch)                     // 忽略空字符
                {  
                    ans += ch;
                }
            }
        }

        return ans;
    }
};


class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.size(), row = numRows;

        // 如果行数为 1 或行数大于等于字符串长度，直接返回字符串
        if (row == 1 || row >= n)
        {
            return s;
        }

        // cycle 表示一个周期的长度，包含向下和向右上两个方向的字符数
        int cycle = 2 * row - 2;

        // 计算列数 column，列数通过周期长度 cycle 和字符串长度 n 来计算
        int column = (n + cycle - 1) / cycle * (row - 1);

        // 创建二维矩阵 temp 来保存 Z 字形排列的字符
        vector<vector<char>> temp(row, vector<char>(column, '\0'));

        // 填充矩阵
        for (int i = 0, x = 0, y = 0; i < n; i++)
        {
            temp[x][y] = s[i];

            // 判断是否向下或向上
            if (i % cycle < row - 1)
            {
                x++;  
            }
            else
            {
                x--;  
                y++; 
            }
        }

        // 将矩阵中的非空字符按行读取，组成最终结果
        string ret;
        for (auto& x : temp)
        {
            for (char ch : x)
            {
                if (ch != '\0') 
                {
                    ret += ch;
                }
            }
        }

        return ret;
    }
};


//压缩矩阵空间，优化：
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length(), r = numRows;

        // 如果行数为 1 或行数大于等于字符串长度，直接返回原字符串
        if (r == 1 || r >= n)
        {
            return s;
        }

        // 创建一个 vector 用来存储每行的字符
        vector<string> mat(r);

        // 计算周期长度，包含向下和向右上两个方向的字符数
        int cycle = r * 2 - 2;

        // 填充矩阵，模拟 Z 字形排列
        for (int i = 0, x = 0; i < n; ++i)
        {
            mat[x] += s[i];  // 将字符 s[i] 添加到对应行的字符串中

            // 判断是向下移动还是向上移动
            if (i % cycle < r - 1)
            {
                ++x;  // 向下移动
            }
            else
            {
                --x;  // 向上移动
            }
        }

        // 拼接所有行，得到最终的 Z 字形字符串
        string ans;
        for (auto& row : mat)
        {
            ans += row;
        }

        return ans;
    }
};






//方法二：模拟 + 找规律
//时间复杂度：O(n)
//算法原理：
//找规律，⽤ row 代替⾏数，row = 4 时画出的 N 字形如下：
//0                             2row - 2                            4row - 4
//1               2row - 3 2    row - 1                 4row - 5    4row - 3
//2   2row - 4                  2row        4row - 6                4row - 2
//3                             2row + 1                            4row - 1
//不难发现，数据是以 2row - 2 为⼀个周期进⾏规律变换的。将所有数替换成⽤周期来表⽰的变量：
//第⼀⾏的数是：0, 2row - 2, 4row - 4；
//第⼆⾏的数是：1, (2row - 2) - 1, (2row - 2) + 1, (4row - 4) - 1, (4row - 4) + 1；
//第三⾏的数是：2, (2row - 2) - 2, (2row - 2) + 2, (4row - 4) - 2, (4row - 4) + 2；
//第四⾏的数是：3, (2row - 2) + 3, (4row - 4) + 3。
//可以观察到，第⼀⾏、第四⾏为差为 2row - 2 的等差数列；第⼆⾏、第三⾏除了第⼀个数取值为⾏
//数，每组下标为(2n - 1, 2n)的数围绕（2row - 2）的倍数左右取值。
//以此规律，我们可以写出迭代算法。
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)                                 // 如果只有 1 行，直接返回原字符串
        {
            return s;
        }

        string result;                                    // 存储最终的 Z 字形变换结果
        int n = s.size();                                 // 获取字符串长度
        int cycleLen = 2 * numRows - 2;                   // 计算周期长度（Cycle Length）

        // 第一行：每个周期的第一个字符
        for (int i = 0; i < n; i += cycleLen)
        {
            result += s[i];
        }

        // 中间行：每行需要考虑两个位置
        for (int row = 1; row < numRows - 1; row++)
        {
            for (int i = row, j = cycleLen - row; j < n || i < n; i += cycleLen, j += cycleLen)
            {
                if (i < n)                                // 检查 i 是否越界
                {
                    result += s[i];
                }

                if (j < n)                                // 检查 j 是否越界
                {
                    result += s[j];
                }
            }
        }

        // 最后一行：每个周期的最后一个字符
        for (int i = numRows - 1; i < n; i += cycleLen)
        {
            result += s[i];
        }

        return result;
    }
};
