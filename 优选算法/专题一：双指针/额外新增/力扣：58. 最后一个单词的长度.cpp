// 力扣：58. 最后一个单词的长度
// 链接：https://leetcode.cn/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：IO流
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string ret, temp;
        stringstream ss;
        ss << s;

        while (ss >> temp)
        {
            ret = temp;
        }

        return ret.size();
    }
};


// 更加优雅的写法：
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        stringstream ss(s); // 直接用构造函数传参，不用 ss << s
        string temp;
        while (ss >> temp)
        {

        }

        return temp.size();
    }
};




// 方法二：双指针模拟
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        // 1.从后往前跳过空格
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        int len = 0;    // 长度
        while (i >= 0 && s[i] != ' ')
        {
            i--;
            len++;
        }

        return len;
    }
};