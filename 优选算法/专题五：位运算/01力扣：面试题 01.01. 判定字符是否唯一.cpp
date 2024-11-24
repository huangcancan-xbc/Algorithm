//力扣：面试题 01.01. 判定字符是否唯一
//https://leetcode.cn/problems/is-unique-lcci/description/


//方法一：哈希表
//时间复杂度：O(n)
class Solution {
public:
    bool isUnique(string astr) {
        int hash[26] = { 0 };                   // 数组模拟哈希表，26个字符初始化为0
        for (auto x : astr)
        {
            if (hash[x - 'a'] > 0)              // 检查当前字符是否已经出现过
            {
                return false;                   // 如果出现过，则返回 false
            }

            hash[x - 'a']++;                    // 标记当前字符出现过
        }

        return true;
    }
};





// 方法二：位图（Bitmap）
// 算法原理：利用一个整型变量作为位图来标记字符是否出现过。

// 注意：
// 鸽巢原理（Pigeonhole Principle）：如果字符串的长度大于26（字母表的大小），
// 则一定会有重复字符，因此可以直接返回 false。
class Solution {
public:
    bool isUnique(string astr) {
        // 利用鸽巢原理进行初步优化
        if (astr.size() > 26) 
        {
            return false;                           // 字符串长度大于26，必有重复字符
        }

        int bitmap = 0;                             // 位图，初始为0
        for (char x : astr) 
        {
            int i = x - 'a';                        // 计算字符在字母表中的索引

            // 检查当前字符是否已经出现
            if ((bitmap >> i) & 1) 
            {
                return false;                       // 如果已经出现，则返回 false
            }

            // 标记当前字符已出现
            bitmap |= 1 << i;                       // 将位图的第 i 位设置为 1
        }

        return true;                                // 若没有重复字符，则返回 true
    }
};