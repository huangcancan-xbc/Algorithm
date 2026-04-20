// 力扣：242. 有效的字母异位词
// 链接：https://leetcode.cn/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int hash1[26] = { 0 };
        int hash2[26] = { 0 };

        for (int i = 0; i < s.size(); i++)
        {
            hash1[s[i] - 'a']++;
            hash2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (hash1[i] != hash2[i])
            {
                return false;
            }
        }

        return true;
    }
};




// 一个数组优化：
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int hash[26] = { 0 };

        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (hash[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};