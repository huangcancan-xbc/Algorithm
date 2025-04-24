// 力扣：397. 整数替换
// 链接：https://leetcode.cn/problems/integer-replacement/description/

// 方法一：递归
//注意：数据范围可达 int 最大值，当 n+1 时可能会导致溢出，因此需要使用long long类型进行运算
class Solution
{
public:
    int integerReplacement(int n)
    {
        return dfs(n);                                  // 调用递归函数
    }

    int dfs(long long n)                                // 避免溢出，使用long long类型进行运算
    {
        if (n == 1)
        {
            return 0;                                   // 递归出口：n=1时，不需要替换，返回0
        }

        if (n % 2 == 0)
        {
            return 1 + dfs(n / 2);                      // 递归：n为偶数，则替换为n/2，需要1步
        }
        else
        {
            return min(dfs(n + 1), dfs(n - 1)) + 1;     // 递归：n为奇数，则替换为n+1或n-1，需要1步，取最小值
        }
    }
};

// 记忆化搜索：
class Solution
{
public:
    unordered_map<int, int> hash;                       // 定义哈希表，用于记忆化搜索，避免重复计算
    int integerReplacement(int n)
    {
        return dfs(n);
    }

    int dfs(long long n)
    {
        if (hash.count(n))
        {
            return hash[n];                             // 查找哈希表，若已计算过当前值，直接返回结果，避免重复计算
        }

        if (n == 1)
        {
            hash[1] = 0;                                // 递归出口：当 n 为 1 时，不需要任何操作，返回 0
            return 0;
        }

        if (n % 2 == 0)
        {
            hash[n] = 1 + dfs(n / 2);                   // 若 n 为偶数，直接除以 2，替换步骤数 +1
            return hash[n];
        }
        else
        {
            hash[n] = min(dfs(n + 1), dfs(n - 1)) + 1;  // 若 n 为奇数，有两种操作选择：+1 或 -1，取最小步骤数
            return hash[n];
        }
    }
};


// 方法二：二进制贪心
class Solution
{
public:
    int integerReplacement(int n)
    {
        int ret = 0;                                    // 记录替换次数
        while (n > 1)                                   // 当 n 大于 1 时，不断进行替换
        {
            if (n % 2 == 0)                             // 若 n 为偶数，直接除以 2，操作次数 +1
            {
                n /= 2;
                ret++;
            }
            else
            {
                if (n == 3)                             // 若 n 为 3，特殊处理，需两步：先减 1，再除 2，直接返回结果
                {
                    ret += 2;
                    n = 1;                              // 或者 n /= 2;
                }
                else if (n % 4 == 1)                    // 若 n 是奇数且 n % 4 == 1（例如 5 -> 4 -> 2 -> 1），选择 -1 操作更优
                {
                    n /= 2;
                    ret += 2;
                }
                else                                    // 若 n 是奇数且 n % 4 == 3（例如 7 -> 8 -> 4 -> 2 -> 1），选择 +1 操作更优
                {
                    n = n / 2 + 1;
                    ret += 2;
                }
            }
        }

        return ret;
    }
};