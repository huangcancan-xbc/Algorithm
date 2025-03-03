//力扣：784. 字母大小写全排列
//链接：https://leetcode.cn/problems/letter-case-permutation/description/


//方法：DFS

//最简单最直接的写法：
class Solution
{
public:
    vector<string> ret;                     // 用于存储最终结果
    string path;                            // 当前递归路径

    void dfs(const string& s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);            // 如果已经递归到字符串的末尾，将当前路径加入结果中
            return;
        }

        if ((s[pos] >= 'a' && s[pos] <= 'z') || (s[pos] >= 'A' && s[pos] <= 'Z'))   // 如果当前字符是字母
        {
            path += tolower(s[pos]);        // 转为小写并加入路径
            dfs(s, pos + 1);                // 递归
            path.pop_back();                // 回溯

            path += toupper(s[pos]);        // 转为大写并加入路径
            dfs(s, pos + 1);                // 递归
            path.pop_back();                // 回溯
        }
        else
        {
            path += s[pos];                 // 直接加入路径
            dfs(s, pos + 1);                // 递归
            path.pop_back();                // 回溯
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);
        return ret;
    }
};

//使用函数写法：
class Solution
{
public:
    vector<string> ret;
    string path;

    void dfs(const string& s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);            // 如果已经递归到字符串的末尾，将当前路径加入结果中
            return;
        }

        // 处理当前字符
        if (isalpha(s[pos]))                // 如果是字母
        {
            path.push_back(tolower(s[pos]));// 转为小写并加入路径
            dfs(s, pos + 1);
            path.pop_back();

            path.push_back(toupper(s[pos]));// 转为大写并加入路径
            dfs(s, pos + 1);
            path.pop_back();
        }
        else                                // 如果是数字或符号
        {
            path.push_back(s[pos]);
            dfs(s, pos + 1);
            path.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);
        return ret;
    }
};




//算法原理：
//只需要对英⽂字⺟进⾏处理，处理每个元素时存在三种情况：
//1. 不进⾏处理；
//2. 若当前字⺟是英⽂字⺟并且是⼤写，将其修改为⼩写；
//3. 若当前字⺟是英⽂字⺟并且是⼩写，将其修改为⼤写。
//
//从前往后按序进⾏递归，递归流程如下：
//1. 递归结束条件：当前需要处理的元素下标越界，表⽰处理完毕，记录当前状态并返回；
//2. 对当前元素不进⾏任何处理，直接递归下⼀位元素；
//3. 判断当前元素是否为⼩写字⺟，若是，将其修改为⼤写字⺟并递归下⼀个元素，递归结束时撤销修改操作；
//4. 判断当前元素是否为⼤写字⺟，若是，将其修改为⼩写字⺟并递归下⼀个元素，递归结束时撤销修改操作；
class Solution
{
public:
    string path;
    vector<string> ret;

    char change(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;                       // 小写字母转为大写
        }
        else
        {
            ch += 32;                       // 大写字母转为小写
        }

        return ch;
    }

    void dfs(const string& s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }

        // 处理当前字符，加入到路径
        char ch = s[pos];
        path.push_back(ch);
        dfs(s, pos + 1);
        path.pop_back();

        if (ch < '0' || ch>'9')             // 如果当前字符不是数字，考虑其大小写转换
        {
            char temp = change(ch);         // 改变字符的大小写
            path.push_back(temp);
            dfs(s, pos + 1);
            path.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);
        return ret;
    }
};

//使用函数写法：
class Solution
{
public:
    string path;
    vector<string> ret;

    void dfs(const string& s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);            // 如果遍历到字符串末尾，将当前路径添加到结果中
            return;
        }

        // 不改变当前字符，直接递归
        char ch = s[pos];
        path.push_back(ch);
        dfs(s, pos + 1);
        path.pop_back();

        // 如果当前字符是字母，则尝试大小写转换
        if (isalpha(ch))                    // 判断是否为字母
        {
            char temp = islower(ch) ? toupper(ch) : tolower(ch); // 根据当前大小写转换
            path.push_back(temp);
            dfs(s, pos + 1);
            path.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        dfs(s, 0);
        return ret;
    }
};

//将 path 作为参数传入的写法：
class Solution
{
public:
    vector<string> ret;

    char change(char ch)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch -= 32;                       // 小写字母转为大写
        }
        else
        {
            ch += 32;                       // 大写字母转为小写
        }

        return ch;
    }

    void dfs(const string& s, int pos, string& path)
    {
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }

        // 处理当前字符，加入到路径
        char ch = s[pos];
        path.push_back(ch);
        dfs(s, pos + 1, path);
        path.pop_back();

        if (ch < '0' || ch>'9')             // 如果当前字符不是数字，考虑其大小写转换
        {
            char temp = change(ch);         // 改变字符的大小写
            path.push_back(temp);
            dfs(s, pos + 1, path);
            path.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s)
    {
        string path;
        dfs(s, 0, path);
        return ret;
    }
};