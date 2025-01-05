//力扣：49. 字母异位词分组
//链接：https://leetcode.cn/problems/group-anagrams/description/



//方法：哈希表 + 排序

//算法原理：
//互为字⺟异位词的单词有⼀个特点：将它们「排序」之后，两个单词应该是「完全相同」的。
//所以，我们可以利⽤这个特性，将单词按照字典序排序，如果排序后的单词相同的话，就划分到同⼀组中。

//这时我们就要处理两个问题：
//	• 排序后的单词与原单词需要能互相映射；
//	• 将排序后相同的单词，「划分到同⼀组」；

//利⽤语⾔提供的「容器」的强⼤的功能就能实现这两点：
//	• 将排序后的字符串（ string ）当做哈希表的 key 值；
//	• 将字⺟异位词数组（ string[] ）当成 val 值。
//定义⼀个「哈希表」即可解决问题。
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // 使用 unordered_map 来将字母异位词分组，键为排序后的字符串，值为相同字母异位词的集合
        unordered_map<string, vector<string>> hash;

        // 遍历所有字符串，将每个字符串排序后作为 key 存储（将所有字母异位词分组）
        for (auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());           // 排序获取字母异位词的标准形式
            hash[tmp].push_back(s);                 // 将原字符串加入到对应的组中
        }

        // 提取结果：将 unordered_map 中的所有值提取为最终的二维数组
        vector<vector<string>> ret;
        for (auto& [x, y] : hash)
        {
            ret.push_back(y);
        }

        return ret;
    }
};