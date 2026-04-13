// 力扣：383. 赎金信
// 链接：https://leetcode.cn/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
        {
            return false;
        }

        unordered_map<char, int> hash;
        for (auto& x : magazine)
        {
            hash[x]++;
        }

        for (auto& x : ransomNote)
        {
            if (!hash.count(x) || --hash[x] < 0)
            {
                return false;
            }
        }

        return true;
    }
};




// 数组优化：
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (magazine.size() < ransomNote.size())
        {
            return false;
        }

        int hash[26] = { 0 };
        for (char c : magazine)
        {
            hash[c - 'a']++;
        }

        for (char c : ransomNote)
        {
            if (--hash[c - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};