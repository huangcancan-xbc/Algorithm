// 力扣：13. 罗马数字转整数
// 链接：https://leetcode.cn/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希 + 模拟
class Solution
{
public:
    unordered_map<char, int> hash1 = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    unordered_map<string, int> hash2 = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
    };

    int romanToInt(string s)
    {
        int ret = 0;

        int index = 0;
        while (index < s.size())
        {
            // 当2个字符在合法区间的时候，看看他们是不是6个特殊字符，如果是直接加上特殊值
            // 并且往后走2个位置，注意特殊字符可能连续，所以用循环处理
            while (index + 1 < s.size() && hash2.count(s.substr(index, 2)))
            {
                ret += hash2[s.substr(index, 2)];
                index += 2;
            }

            ret += hash1[s[index]];
            index++;
        }

        return ret;
    }
};




// 写法变化：直接模拟
class Solution
{
public:

    unordered_map<char, int> hash = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

    int romanToInt(string s)
    {
        int ret = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && hash[s[i]] < hash[s[i + 1]])
            {
                ret += hash[s[i + 1]] - hash[s[i]];
                i++;
            }
            else
            {
                ret += hash[s[i]];
            }
        }

        return ret;
    }
};