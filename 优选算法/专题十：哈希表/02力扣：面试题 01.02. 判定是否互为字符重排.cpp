//力扣：面试题 01.02. 判定是否互为字符重排
//链接：https://leetcode.cn/problems/check-permutation-lcci/description/


//方法：哈希表

//算法原理：
//1. 当两个字符串的⻓度不相等的时候，是不可能构成互相重排的，直接返回 false ；
//2. 如果两个字符串能够构成互相重排，那么每个字符串中「各个字符」出现的「次数」⼀定是相同的。
//因此，我们可以分别统计出这两个字符串中各个字符出现的次数，然后逐个⽐较是否相等即可。这样的话，我们就可以选择「哈希表」来统计字符串中字符出现的次数。
class Solution {
public:
    bool CheckPermutation(string s1, string s2) 
    {
        if (s1.size() != s2.size())             // 字符串长度不同，肯定不一样
        {
            return  false;
        }

        int hash1[26] = { 0 };                  // 26个字母的哈希表，注意要显式的初始化和字符要减去'a'
        int hash2[26] = { 0 };

        for (auto x : s1)
        {
            hash1[x - 'a']++;
        }

        for (auto x : s2)
        {
            hash2[x - 'a']++;
        }

        for (int i = 0; i < 26; i++)            // 哈希表比较
        {
            if (hash1[i] != hash2[i])           // 不同字符数量不同，肯定不一样
            {
                return false;
            }
        }

        return true;
    }
};



//一个哈希表的优化版本
class Solution {
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size())                     // 如果两个字符串长度不同，则一定不能构成排列关系
        {
            return false;
        }

        // 定义哈希表，用于记录26个字母的出现次数
        int hash[26] = { 0 };                           // 显式初始化为0，'a'到'z'共有26个字母

        // 遍历第一个字符串，统计每个字符的出现次数
        for (char c : s1)
        {
            hash[c - 'a']++;                            // 字符 - 'a' 将字符映射到哈希表的索引
        }

        // 遍历第二个字符串，同时对哈希表进行相应的减法操作
        for (char c : s2)
        {
            hash[c - 'a']--;
            
            if (hash[c - 'a'] < 0)                      // 如果某个字符的计数小于0，说明两个字符串的字符不匹配
            {
                return false;
            }
        }

        return true;                                    // 遍历结束，两个字符串是互为排列
    }
};
