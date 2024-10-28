//力扣：76. 最小覆盖子串
//https://leetcode.cn/problems/minimum-window-substring/description/


// 方法一：暴力枚举+哈希表
// 时间复杂度：O(n^3) 

// 算法原理：
// 1. 枚举字符串 s 的所有子串，
// 2. 使用哈希表统计每个子串中字符的频率，
// 3. 判断当前子串是否包含 t 中所有字符及其频率，
// 4. 记录满足条件的最小子串。

class Solution {
public:
    string minWindow(string s, string t) {
        int s_len = s.size();
        int t_len = t.size();
        string result = "";                        // 用于存储结果
        int min_len = INT_MAX;                     // 初始化最小长度为最大值

        // 枚举所有可能的子串
        for (int start = 0; start < s_len; start++) 
        {
            for (int end = start; end < s_len; end++) 
            {
                string sub = s.substr(start, end - start + 1); // 获取子串

                if (isValid(sub, t))                    // 检查子串是否有效
                {
                    if (sub.size() < min_len)           // 更新最小有效子串
                    {      
                        min_len = sub.size();
                        result = sub;                   // 更新结果
                    }
                }
            }
        }

        return result;                             
    }

private:
    bool isValid(const string& sub, const string& t) {
        vector<int> hash_t(128, 0);               // 统计 t 中字符频率
        vector<int> hash_sub(128, 0);             // 统计子串中字符频率

        for (char c : t) 
        {
            hash_t[c]++;                           // 更新 t 中字符频率
        }

        for (char c : sub) 
        {
            hash_sub[c]++;                         // 更新子串字符频率
        }

        // 检查子串是否包含 t 中所有字符及其频率
        for (char c : t) 
        {
            if (hash_sub[c] < hash_t[c]) 
            {
                return false;                      // 不满足条件
            }
        }

        return true;                               // 满足条件
    }
};







//方法二：滑动窗口+哈希表
//时间复杂度：O(n)

//算法原理：
// 1. 使用两个哈希表分别统计字符串 t 和当前窗口中字符的频率，
// 2. 扩展右边界直到满足 t 中所有字符的条件，
// 3. 尝试收缩左边界以找到最小的有效窗口。
// 4. 当窗口符合条件时，更新最小窗口的长度和起始位置。
class Solution {
public:
    string minWindow(string s, string t) {
        char hash1[128] = { 0 };                    // 用来存储字符串 t 中字符的频率
        char hash2[128] = { 0 };                    // 用来追踪当前窗口中字符串 s 的字符频率
        int kinds = 0;                              // 记录字符串 t 中有效字符有多少种

        // 初始化 hash1，统计 t 中的字符频率
        for (auto x : t)
        {
            if (hash1[x] == 0)                      // 如果该字符是 t 中第一次出现，则增加 'kinds'
            {
                kinds++;                            // 统计 t 中不同字符的数量
            }
            hash1[x]++;                             // 增加该字符在 t 中的频率
        }

        int min_len = INT_MAX;                      // 存储最小有效窗口的长度
        int begin = -1;                             // 存储窗口左端点

        // 'left' 表示窗口的左边界，'right' 表示窗口的右边界
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];                     // 'in' 是即将进入窗口的字符
            hash2[in]++;                            // 增加该字符在窗口中的频率

            // 如果该字符的频率在窗口中达到了 t 中要求的频率，则增加 'count'
            if (hash2[in] == hash1[in])
            {
                count++;                            // 满足条件的字符数量加1
            }

            // 当窗口中的字符频率满足 t 的要求时，尝试缩小窗口
            while (kinds == count)
            {
                // 如果当前窗口比之前找到的最小窗口还要小，则更新最小窗口
                if (right - left + 1 < min_len)
                {
                    min_len = right - left + 1;     // 更新最小窗口长度
                    begin = left;                   // 记录最小窗口的起始位置
                }

                char out = s[left++];               // 'out' 是即将移出窗口的字符
                // 如果移出该字符导致其频率小于 t 中的要求，则减少 'count'
                if (hash2[out]-- == hash1[out])
                {
                    count--;                        // 不再满足条件的字符，数量减1
                }
            }
        }

        // 如果 'begin' 仍然是 -1，表示没有找到有效的窗口，返回空字符串
        if (begin == -1)
        {
            return "";
        }
        else
        {
            // 返回最小有效窗口的子字符串
            return s.substr(begin, min_len);
        }
    }
};
//说明：
//hash1：该数组存储了字符串 t 中每个字符出现的频率，帮助判断窗口中是否包含足够的字符。
//hash2：该数组用于追踪当前窗口中字符串 s 的字符频率，方便与 t 进行比较。
//kinds：记录字符串 t 中独特字符的总数。当窗口中所有字符频率匹配时，尝试缩小窗口。
//count：追踪当前窗口中，满足字符频率要求的字符数量。
//min_len：存储最小有效窗口的长度。
//begin：存储最小有效窗口的起始位置。