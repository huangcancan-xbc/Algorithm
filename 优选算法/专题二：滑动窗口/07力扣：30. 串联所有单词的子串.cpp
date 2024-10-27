//力扣：30. 串联所有单词的子串
//https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
//在代码里，使用& 来避免不必要的拷贝，虽然对小型对象如 string 的影响不大，但对于更大的对象，引用可以带来显著的性能提升。


//方法一：暴力枚举
//时间复杂度：O(n*m*k)，n为字符串s的长度，m为单词数组words的长度，k为单词的平均长度
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;                           // 保存所有符合条件的起始索引
        int n = s.size();                          // 字符串 s 的长度
        int m = words.size();                      // words 中的单词数
        int len = words[0].size();                 // 每个单词的长度
        int totalLen = m * len;                    // 所有单词拼接在一起的总长度

        // 暴力遍历每个可能的起点
        for (int i = 0; i <= n - totalLen; i++)
        {
            unordered_map<string, int> hash1;      // 统计每个单词在 words 中的出现次数
            for (auto& x : words)
            {
                hash1[x]++;                        // 初始化单词频率
            }

            bool valid = true;                     // 标志当前起点是否有效
            for (int j = 0; j < m; j++)
            {
                // 提取从当前起点 i 开始的单词
                string word = s.substr(i + j * len, len);

                // 检查提取的单词是否在 words 中
                if (hash1.find(word) == hash1.end())
                {
                    valid = false;                 // 如果单词不在 words 中，标记为无效
                    break;                         // 直接退出循环
                }

                hash1[word]--;                     // 单词频率减少
                if (hash1[word] < 0)
                {
                    valid = false;                 // 如果频率小于 0，说明单词数量不匹配
                    break;                         // 退出循环
                }
            }

            if (valid)
            {
                ret.push_back(i);                  // 如果有效，保存起点索引
            }
        }

        return ret;                                // 返回结果集
    }
};






//方法二：滑动窗口+哈希表
//时间复杂度：O(n*m*k)，n为字符串s的长度，m为单词数组words的长度，k为单词的平均长度

//算法原理：
// 如果我们把每⼀个单词看成⼀个⼀个字⺟，问题就变成了找到「字符串中所有的字⺟异位词」。⽆⾮就是之前处理的对象是⼀个⼀个的字符，我们这⾥处理的对象是⼀个⼀个的单词。

//为了优化算法，并且题目中：“words 中所有字符串 长度相同” 还特地将字体加粗处理，所以我们可以采用一个非常巧妙的方法：
//将 words 数组中的每一小个子串看成一个整体，例如 words = ["foo","bar"]，将 "foo" 和 "bar" 分别看成 “a” “b”
//再将 s 字符串按words子串的长度切分，例如 s = "barfoothefoobarman"，切分为[bar,foo,the,foo,bar,man]
//这样就成了 06力扣：438. 找到字符串中所有字母异位词 的问题，求解起来就简单多了。

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;                               // 保存所有符合条件的起始索引的结果集
        unordered_map<string, int> hash1;              // 记录单词列表中每个单词出现的频率

        // 统计每个单词在 words 中的出现次数
        for (auto& x : words) 
        {
            hash1[x]++;                                // 每个单词对应的计数加一
        }

        int len = words[0].size();                     // 每个单词的长度
        int m = words.size();                          // 单词的总数

        // 从每个可能的起点开始滑动窗口，最多遍历 len 次，确保所有字符都能被覆盖
        for (int i = 0; i < len; i++) 
        {
            unordered_map<string, int> hash2;          // 记录当前窗口内单词出现的频率
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len) 
            {
                string in = s.substr(right, len);      // 从右指针位置提取当前单词
                hash2[in]++;                           // 记录该单词在当前窗口中的频率

                // 如果当前单词在 words 中，且出现次数符合要求，计数加一
                if (hash1.count(in) && hash2[in] <= hash1[in]) 
                {
                    count++;
                }

                // 当窗口大小超过单词数组总长度时，左指针右移
                if (right - left + 1 > m * len) 
                {
                    string out = s.substr(left, len);  // 从左指针位置提取移出的单词

                    // 如果移出的单词在 words 中且频率符合条件，计数减一
                    if (hash1.count(out) && hash2[out] <= hash1[out]) 
                    {
                        count--;
                    }

                    hash2[out]--;                     // 更新移出单词的频率
                    left += len;                      // 移动左指针，保持窗口大小
                }

                // 当窗口中的单词数与 words 的单词数匹配时，记录左指针位置为一个结果
                if (count == m) 
                {
                    ret.push_back(left);              // 将符合条件的起始索引加入结果集
                }
            }
        }

        return ret;                                   // 返回结果集
    }
};
//注意：
//使用[]查找元素时，如果元素不存在，map和unordered_map容器都是创建一个空的元素；如果存在，会正常索引对应的值。
//所以如果查询过多的不存在的元素值，容器内部会创建大量的空的键值对，后续查询创建删除效率会大大降低。
//因此，建议使用count()函数来判断元素是否存在，避免频繁的创建删除键值对。
//所以两处 hash1.count() 不加也能正常通过力扣，但是加上之后会使时间复杂度降低。从而增加效率。