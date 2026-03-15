// 力扣：151. 反转字符串中的单词
// 链接：https://leetcode.cn/problems/reverse-words-in-a-string/description/

// 方法一：使用字符串流
class Solution
{
public:
    string reverseWords(string s)
    {
        string ret = "", word;
        stringstream ss(s);
        while (ss >> word)
        {
            ret = word + (ret.empty() ? "" : " ") + ret;
        }

        return ret;
    }
};



// 方法二：模拟
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size(), i = n - 1;
        string ret;

        while (i >= 0)
        {
            // 跳过空格
            while (i >= 0 && s[i] == ' ')
            {
                i--;
            }
            if (i < 0)
            {
                break;
            }

            // 开始找单词的开头
            int j = i;
            while (i >= 0 && s[i] != ' ')
            {
                i--;
            }

            // 拼接字符串
            if (!ret.empty())
            {
                ret += " ";
            }
            ret += s.substr(i + 1, j - i);
        }

        return ret;
    }
};