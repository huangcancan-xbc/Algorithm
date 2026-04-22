// 力扣：71. 简化路径
// 链接：https://leetcode.cn/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：栈 + 流
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack;
        stringstream ss(path);
        string str;

        while (getline(ss, str, '/'))
        {
            if (str == "" || str == ".")
            {
                continue;
            }
            else if (str == "..")
            {
                // 注意：这个条件不能用&&放到上面，因为"/.."这种情况第一次会读到空（""），第二次直接进条件三（else）
                // 不能把2个前后条件合并成一个条件！！！
                if (!stack.empty())
                {
                    stack.pop_back();
                }
            }
            else
            {
                stack.push_back(str);
            }
        }

        if (stack.empty())
        {
            return "/";
        }

        string ret;
        for (auto& x : stack)
        {
            ret += "/" + x;
        }

        return ret;
    }
};




// 栈 + 手动模拟分割（不使用流）
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack;
        int i = 0;
        while (i < path.size())
        {
            int j = i;
            while (j < path.size() && path[j] != '/')
            {
                j++;
            }
            string str = path.substr(i, j - i);
            i = j + 1;

            if (str == "" || str == ".")
            {
                continue;
            }
            else if (str == "..")
            {
                if (!stack.empty())
                {
                    stack.pop_back();
                }
            }
            else
            {
                stack.push_back(str);
            }
        }

        if (stack.empty())
        {
            return "/";
        }

        string ret;
        for (auto& x : stack)
        {
            ret += "/" + x;
        }

        return ret;
    }
};