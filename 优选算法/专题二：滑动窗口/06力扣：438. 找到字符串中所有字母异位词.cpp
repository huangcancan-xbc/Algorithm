//力扣：438. 找到字符串中所有字母异位词
//https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
//很幸运这里的四个代码都能通过力扣测试

//方法一；暴力法
//时间复杂度：O(n^2)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;                        // 用于存储结果
        int m = p.size(), n = s.size();         // m 是目标字符串的长度，n 是源字符串的长度

        if (n < m) return ret;                  // 源字符串长度小于目标字符串时，直接返回空结果

        // 对目标字符串 p 进行字符频次计数
        vector<int> hash1(26, 0);               // 存储目标字符串 p 中每个字符的频次
        for (char ch : p) 
        {
            hash1[ch - 'a']++;
        }

        // 遍历源字符串 s，检查每个长度为 m 的子串是否是字母异位词
        for (int i = 0; i <= n - m; i++) 
        {
            vector<int> hash2(26, 0);           // 存储当前子串中的字符频次

            for (int j = 0; j < m; j++) 
            {
                hash2[s[i + j] - 'a']++;
            }

            if (hash1 == hash2)                 // 如果两个频次相同，则说明找到了字母异位词
            {               
                ret.push_back(i);
            }
        }
        return ret;
    }
};







//方法二：滑动窗口+哈希表
//不使用 count 的优化方法（O(26n) 时间复杂度）：
//不使用 count 来记录匹配的字符数，而是每次都直接比较两个哈希表的频次是否相同：
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;                        // 存储结果
        int m = p.size();                       // p 的长度
        int n = s.size();                       // s 的长度

        if (n < m) return ret;                  // 若 s 比 p 短，直接返回空结果

        int hash1[26] = { 0 };                  // 存储 p 的字符频次
        int hash2[26] = { 0 };                  // 存储当前窗口的字符频次

        // 记录 p 的字符频次
        for (char ch : p)
            hash1[ch - 'a']++;

        // 遍历 s，维护一个大小为 m 的滑动窗口
        for (int i = 0; i < n; i++) 
        {
            hash2[s[i] - 'a']++;                // 将当前字符加入窗口

            if (i >= m)                         // 当窗口大小超过 m 时
            {                       
                hash2[s[i - m] - 'a']--;        // 移出左边界的字符
            }

            // 如果两个频次表相同，记录结果
            if (memcmp(hash1, hash2, 26 * sizeof(int)) == 0) 
            {
                ret.push_back(i - m + 1);       // 记录窗口的起始位置
            }
        }

        return ret;
    }
};



//下面是两个优化后的代码，思路一模一样，任意选择一个好理解的即可。

//算法原理：滑动窗口+哈希表
//时间复杂度：O(n)

//优化：更新结果的判断条件：
//用一个变量count记录当前窗口中符合条件的字符数，当count等于目标字符串p的长度时，说明找到了一个字母异位词，记录当前窗口的起始位置。
//优化：用两个哈希表hash1和hash2分别存储目标字符串p和当前窗口中的字符频次。
//优化：用一个变量left记录当前窗口的左边界，用一个变量right记录当前窗口的右边界，用一个变量count记录当前窗口中符合条件的字符数。    
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;                // 用于存储找到的起始索引

        int hash1[26] = { 0 };          // 存储目标字符串 p 中每个字符的出现次数
        int hash2[26] = { 0 };          // 存储当前窗口中每个字符的出现次数
        int m = p.size();               // 目标字符串 p 的长度（窗口大小）

        for (auto ch : p)
            hash1[ch - 'a']++;          // 初始化目标字符串的字符频次

        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];         // 当前进入窗口的字符

            if (++hash2[in - 'a'] <= hash1[in - 'a'])
                count++;                // 如果字符频次符合目标字符串，则增加计数

            if (right - left + 1 > m)   // 当窗口超过目标长度时
            {
                char out = s[left++];   // 当前离开窗口的字符

                if (--hash2[out - 'a'] <= hash1[out - 'a'])
                    count--;            // 如果移出的字符频次符合目标，则减少计数
            }

            if (count == m)             // 当窗口内字符匹配时
                ret.push_back(left);    // 记录窗口的起始位置
        }

        return ret;                   
    }
};



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26] = { 0 };        // s中当前窗口的字母计数
        int hash2[26] = { 0 };        // p中每个字母的计数
        vector<int> ret;              // 存储字母异位词起始位置

        for (char x : p)
        {
            hash2[x - 'a']++;         // 记录p中各字母的频率
        }

        //count 记录了窗口中有多少字符频次是匹配的，当 count 等于 p.size() 时，就找到了一个字母异位词。(用来记录 当前窗口 中符合条件的字符数)
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            if (++hash1[s[right] - 'a'] <= hash2[s[right] - 'a'])
            {
                count++;              // 若当前字母频率未超过p中的频率，增加匹配计数
            }

            if (right - left + 1 > p.size())  // 窗口超过p的长度时
            {
                if (hash1[s[left] - 'a']-- <= hash2[s[left] - 'a'])
                {
                    count--;          // 左边移出字符时减少匹配计数
                }
                left++;               // 左边界右移
            }

            if (count == p.size())    // 当匹配计数等于p的长度时
            {
                ret.push_back(left);  // 记录当前起始位置
            }
        }

        return ret;
    }
};
