// 力扣：73. 矩阵置零
// 链接：https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希
// 思路：用2个哈希表分别记录要处理的行和列，根据哈希表直接去处理就行
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        long n = matrix.size(), m = matrix[0].size();
        long hash1[n];
        long hash2[m];

        // 用memset初始化为0
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));

        for (long i = 0; i < n; i++)
        {
            for (long j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // 非0值基本均可
                    hash1[i] = 666;
                    hash2[j] = 666;
                }
            }
        }

        for (long i = 0; i < n; i++)
        {
            if (hash1[i] == 666)
            {
                for (long j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (long j = 0; j < m; j++)
        {
            if (hash2[j] == 666)
            {
                for (long i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};