// 力扣：290. 单词规律
// 链接：https://leetcode.cn/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> hash1;
        unordered_map<string, char> hash2;

        stringstream ss(s);
        string temp;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (!(ss >> temp))
            {
                return false;
            }

            char a = pattern[i];
            string b = temp;
            if (hash1.count(a) && hash2[b] != a)
            {
                return false;
            }

            if (hash2.count(b) && hash1[a] != b)
            {
                return false;
            }

            hash1[a] = b;
            hash2[b] = a;
        }

        if (ss >> temp)
        {
            return false;
        }

        return true;
    }
};