//力扣：LCR 114. 火星词典
//链接：https://leetcode.cn/problems/Jf1JuT/description/


//方法：拓扑排序

//算法原理：
//将题意搞清楚之后，这道题就变成了判断有向图时候有环，可以⽤拓扑排序解决。
//如何搜集信息（如何建图）：
//a.两层 for 循环枚举出所有的两个字符串的组合；
//b.然后利⽤指针，根据字典序规则找出信息。
class Solution
{
    unordered_map<char, unordered_set<char>> graph;     // 存储字典的图结构
    unordered_map<char, int> in;                        // 存储每个字母的入度
    bool check;                                         // 标记是否存在无效顺序（如前缀问题）

public:
    // 添加边信息：比较两个单词，确定字母间的顺序关系
    void add(string& s1, string& s2)
    {
        int n = min(s1.size(), s2.size());              // 比较最短的长度
        int i = 0;

        for (; i < n; i++)
        {
            if (s1[i] != s2[i])                         // 找到第一个不同的字母
            {
                char a = s1[i], b = s2[i];
                if (!graph.count(a) || !graph[a].count(b)) // 如果没有该顺序关系
                {
                    graph[a].insert(b);                 // 添加边
                    in[b]++;                            // 增加入度
                }
                break;                                  // 只需要找第一个不同字母
            }
        }

        // 如果第二个单词是第一个单词的前缀，且第二个单词比第一个短
        if (i == s2.size() && i < s1.size())
        {
            check = true;                               // 标记无效顺序
        }
    }

    // 主函数：返回火星词典的字母顺序
    string alienOrder(vector<string>& words)
    {
        for (auto& s : words)
        {
            for (auto& ch : s)
            {
                in[ch] = 0;                             // 初始化每个字母的入度为0
            }
        }

        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                add(words[i], words[j]);                // 添加字母间的顺序关系
                if (check)
                {
                    return "";                          // 如果发现无效顺序，则直接返回
                }
            }
        }

        // 拓扑排序
        queue<char> q;
        string ret;

        for (auto [a, b] : in)
        {
            if (b == 0)
            {
                q.push(a);                              // 将所有入度为0的字母加入队列
            }
        }

        // 进行拓扑排序
        while (q.size())
        {
            auto t = q.front();                         // 获取队列头元素
            q.pop();

            ret += t;                                   // 添加到结果中

            // 更新与当前字母有顺序关系的其他字母
            for (auto ch : graph[t])
            {
                in[ch]--;                               // 减少入度
                if (in[ch] == 0)
                {
                    q.push(ch);                         // 如果入度为0，则加入队列
                }
            }
        }

        // 如果结果中有字母的入度不为0，则说明存在环
        for (auto& [a, b] : in)
        {
            if (b != 0)
            {
                return "";
            }
        }

        return ret;                                     // 返回字母顺序
    }
};




//数组模拟哈希表：

class Solution
{
    vector<unordered_set<int>> graph;                   // 字母间的顺序关系图
    vector<int> in;                                     // 字母的入度
    bool check;                                         // 标记是否存在无效顺序（如前缀问题）

public:
    // 构造函数，初始化图和入度数组
    Solution() : graph(26), in(26, 0), check(false) {}

    // 添加边信息：比较两个单词，确定字母间的顺序关系
    void add(string& s1, string& s2)
    {
        int n = min(s1.size(), s2.size());              // 比较最短的长度
        int i = 0;

        for (; i < n; i++)
        {
            if (s1[i] != s2[i])                         // 找到第一个不同的字母
            {
                int a = s1[i] - 'a';                    // 将字符映射到数组索引
                int b = s2[i] - 'a';                    // 将字符映射到数组索引
                if (graph[a].find(b) == graph[a].end()) // 如果没有该顺序关系
                {
                    graph[a].insert(b);                 // 添加边
                    in[b]++;                            // 增加入度
                }
                break;                                  // 只需要找第一个不同字母
            }
        }

        // 如果第二个单词是第一个单词的前缀，且第二个单词比第一个短
        if (i == s2.size() && i < s1.size())
        {
            check = true;                               // 标记无效顺序
        }
    }

    // 主函数：返回火星词典的字母顺序
    string alienOrder(vector<string>& words)
    {
        // 初始化图和入度数组，只为出现过的字符初始化
        for (auto& s : words)
        {
            for (auto& ch : s)
            {
                in[ch - 'a'] = 0;                       // 初始化每个字母的入度为 0
            }
        }

        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                add(words[i], words[j]);                // 添加字母间的顺序关系
                if (check)
                {
                    return "";                          // 如果发现无效顺序，则直接返回
                }
            }
        }

        // 拓扑排序
        queue<int> q;
        string ret;

        // 将所有入度为 0 的字母加入队列
        for (int i = 0; i < 26; i++)
        {
            if (in[i] == 0 && any_of(words.begin(), words.end(), [i](const string& word) {
                return word.find(i + 'a') != string::npos;  // 确保该字母在单词中出现过
                }))
            {
                q.push(i);                              // 只有在单词中出现过的字母才考虑
            }
        }

        // 进行拓扑排序
        while (!q.empty())
        {
            int t = q.front();
            q.pop();

            ret += (t + 'a');                           // 将数字映射回字符

            // 更新与当前字母有顺序关系的其他字母
            for (auto ch : graph[t])
            {
                if (--in[ch] == 0)
                {
                    q.push(ch);                         // 如果减少后的入度为 0，则加入队列
                }
            }
        }

        // 如果结果中有字母的入度不为 0，则说明存在环
        for (int i = 0; i < 26; i++)
        {
            if (in[i] != 0 && any_of(words.begin(), words.end(), [i](const string& word) {
                return word.find(i + 'a') != string::npos;  // 确保该字母在单词中出现过
                }))
            {
                return "";                              // 如果存在环，返回空字符串
            }
        }

        return ret;                                     // 返回字母顺序
    }
};
