// 力扣：LCR 170. 交易逆序对的总数 （原：剑指 Offer . 数组中的逆序对）
// https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/description/


// 方法一：暴力法
// 时间复杂度：O(n)
// 遍历每对元素，判断是否构成逆序对。
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int len = records.size();               //如果缺失的数字不在数组中，则是数组最后一个元素的索引

        for (int i = 0; i < len; i++)
        {
            if (records[i] != i)                // 如果记录不等于索引
            {
                return i;                       // 返回第一个不等于索引的记录
            }
        }

        return len;
    }
};





// 方法二：哈希表
// 时间复杂度：O(n)
// 利用哈希表记录出现的元素及其个数，判断逆序对的数量。
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        unordered_set<int> recordSet;                       // 哈希集合

        // 将所有记录存入哈希集合
        for (int number : records) 
        {
            recordSet.insert(number);                       // 插入数字
        }

        // 遍历从 0 到 n-1 的所有数字，查找缺失的数字
        
        //如果结果为 true（即 i 不在集合中），则说明这个数字是缺失的，可以直接返回它。
        //如果结果为 false（即 i 在集合中），则说明这个数字不是缺失的，继续查找下一个数字。
        
        //如果 i 存在于 recordSet 中，find(i) 会返回指向 i 的迭代器，这个迭代器不等于 recordSet.end()。
        //如果 i 不存在于 recordSet 中，find(i) 返回 recordSet.end()，因此会相等。
        for (int i = 0; i < records.size(); i++) 
        {
            if (recordSet.find(i) == recordSet.end())       // 检查是否存在
            {
                return i;                                   // 返回缺失的数字
            }
        }

        return records.size();                              // 如果没有缺失，返回 n
    }
};





// 方法三：位运算
// 时间复杂度：O(n)
// 通过位运算统计逆序对的数量，提升效率。
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int n = records.size();                        // 数组大小
        int xorAll = 0;                                // 用于计算 0 到 n 的异或
        int xorRecords = 0;                            // 用于计算 records 的异或

        // 计算 0 到 n 的所有数字的异或
        for (int i = 0; i <= n; i++) 
        {
            xorAll ^= i;                               // 进行异或运算
        }

        // 计算 records 数组中所有数字的异或
        for (int number : records) 
        {
            xorRecords ^= number;                      // 进行异或运算
        }

        // 异或结果即为缺失的数字
        return xorAll ^ xorRecords;                    // 返回缺失的数字
    }
};





// 方法四：数学方法（高斯求和公式）
// 时间复杂度：O(n)
// 利用数学公式计算逆序对的数量，适合某些特定场景。
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int n = records.size();                          // 记录数组的大小（包含缺失数字）。
        int expectedSum = (n * (n + 1)) / 2;             // 使用高斯求和公式计算 0 到 n 的总和
        int actualSum = 0;                               // 用于存储实际数组中所有元素的和

        // 计算 records 数组中所有数字的和
        for (int number : records) 
        {
            actualSum += number;                         // 累加实际和
        }

        // 缺失的数字为 预期和 - 实际和
        return expectedSum - actualSum;                  // 返回缺失的数字
    }
};





 // 方法五: 二分查找
 // 时间复杂度：O(n log n)
 // 算法原理：
 // 通过二分查找寻找小于当前元素的个数，从而统计逆序对的数量。

class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0;                              // 左指针
        int right = records.size() - 1;            // 右指针

        while (left < right)                       // 循环条件：左指针小于右指针
        {
            int mid = left + (right - left) / 2;   // 计算中间索引

            if (mid == records[mid])               // 如果中间索引等于中间元素
            {
                left = mid + 1;                    // 更新左指针
            }
            else
            {
                right = mid;                       // 更新右指针
            }
        }

        return left == records[left] ? left + 1 : left; // 返回逆序对的总数
    }
};
