//力扣：433. 最小基因变化
//链接：https://leetcode.cn/problems/minimum-genetic-mutation/description/


//方法：BFS

//算法原理：
//如果将「每次字符串的变换」抽象成图中的「两个顶点和⼀条边」的话，问题就变成了「边权为 1的最短路问题」。
//因此，从起始的字符串开始，来⼀次 bfs 即可。
class Solution 
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> vis;                              // 用于记录已经访问（搜索）过的字符串
        unordered_set<string> hash(bank.begin(), bank.end());   // 存储基因库中的字符串
        string change = "ACGT";

        if (startGene == endGene)
        {
            return 0;                                           // 如果起始字符串和终止字符串相同，则不需要变换
        }
        if (!hash.count(endGene))
        {
            return -1;                                          // 如果终止字符串不在基因库中，则不存在变换
        }

        queue<string> q;
        q.push(startGene);                                      // 起始字符串入队
        vis.insert(startGene);                                  // 标记为已访问
        int ret = 0;                                            // 记录最短变换次数

        while (q.size())
        {
            int size = q.size();
            ret++;

            while (size--)
            {
                string t = q.front();                           // 取出队首字符串
                q.pop();

                for (int i = 0; i < 8; i++)
                {
                    string temp = t;                            // 注意：一定要用临时字符串，否则会导致字符串内容变化
                    for (int j = 0; j < 4; j++)
                    {
                        temp[i] = change[j];                    // 尝试所有可能的变换
                        if (hash.count(temp) && !vis.count(temp))// 如果变换后的字符串在基因库中且未访问过
                        {
                            if (temp == endGene)
                            {
                                return ret;                     // 如果变换后的字符串和终止字符串相同，则返回最短变换次数
                            }

                            q.push(temp);
                            vis.insert(temp);                   // 标记为已访问
                        }
                    }
                }
            }
        }

        return -1;                                              // 如果不存在变换路径，则返回 -1
    }
};




class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        unordered_set<string> vis;
        unordered_set<string> hash(bank.begin(), bank.end());
        string change = "ACGT";

        if (startGene == endGene)
        {
            return 0;
        }
        if (!hash.count(endGene))
        {
            return -1;
        }

        queue<string> q;
        q.push(startGene);
        vis.insert(startGene);
        int ret = 0;

        while (q.size())
        {
            int size = q.size();
            ret++;

            for (int i = 0; i < size; i++)
            {
                string t = q.front();
                q.pop();

                for (int i = 0; i < 8; i++)
                {
                    string temp = t;
                    for (int j = 0; j < 4; j++)
                    {
                        temp[i] = change[j];
                        if (hash.count(temp) && !vis.count(temp))
                        {
                            if (temp == endGene)
                            {
                                return ret;
                            }

                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
        }

        return -1;
    }
};