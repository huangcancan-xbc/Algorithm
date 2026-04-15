// 力扣：205. 同构字符串
// 链接：https://leetcode.cn/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> hash1, hash2;

        for (int i = 0; i < s.size(); i++)
        {
            //if ((hash1.count(s[i]) && hash2[t[i]] != s[i]) || (hash2.count(t[i]) && hash1[s[i]] != t[i]))
            //{
            //    return false;
            //}
            if (hash1.count(s[i]) && hash2[t[i]] != s[i])
            {
                return false;
            }

            if (hash2.count(t[i]) && hash1[s[i]] != t[i])
            {
                return false;
            }

            hash1[s[i]] = t[i];
            hash2[t[i]] = s[i];
        }

        return true;
    }
};