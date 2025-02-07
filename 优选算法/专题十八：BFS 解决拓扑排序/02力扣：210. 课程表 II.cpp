//力扣：210. 课程表 II
//链接：https://leetcode.cn/problems/course-schedule-ii/description/


//方法：拓扑排序(和上一题一样)

//算法原理：
//原问题可以转换成⼀个拓扑排序问题。⽤ BFS 解决拓扑排序即可。
//
//拓扑排序流程：
//a.将所有⼊度为 0 的点加⼊到队列中，同时将他们的顺序加入到结果中；
//b.当队列不空的时候，⼀直循环：
//    i.取出队头元素；
//    ii.将于队头元素相连的顶点的⼊度 - 1；
//    iii.然后判断是否减成 0, 。如果减成 0，就加⼊到队列中和结果中。
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses), ret;

        if (numCourses == 1)
        {
            return { 0 };                       // 只有一个课程，可以直接上
        }

        // 建图
        for (auto x : prerequisites)
        {
            int a = x[0], b = x[1];
            graph[b].push_back(a);
            in[a]++;
        }

        //拓扑排序
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
                ret.push_back(i);               // 先将入度为 0 的点加入队列和结果中
            }
        }

        // BFS
        while (q.size())
        {
            auto t = q.front();
            q.pop();

            for (auto i : graph[t])
            {
                in[i]--;
                if (in[i] == 0)
                {
                    q.push(i);
                    ret.push_back(i);           // 入度为 0 的点加入队列和结果中
                }
            }
        }

        // 判断是否有环
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i])
            {
                return {};
            }
        }

        return ret;
    }
};

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses), ret;

        // 建图
        for (auto x : prerequisites)
        {
            int a = x[0], b = x[1];
            graph[b].push_back(a);
            in[a]++;
        }

        //拓扑排序
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);                      // 先将入度为 0 的点加入队列
            }
        }

        // BFS
        while (q.size())
        {
            auto t = q.front();
            q.pop();

            ret.push_back(t);                   // 每次将队头课程加入结果中

            for (auto i : graph[t])
            {
                in[i]--;
                if (in[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        if (ret.size() == numCourses)
        {
            return ret;                         // 如果结果中有所有课程，直接返回结果
        }
        else
        {
            return {};                          // 否则就无法完成所有课程，返回空
        }
    }
};



//unordered_map<int, int>实现：
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> graph;
        vector<int> in(numCourses), ret;

        if (numCourses == 1)
        {
            return { 0 };                        // 只有一个课程，可以直接上
        }

        // 建图
        for (auto x : prerequisites)
        {
            int a = x[0], b = x[1];
            graph[b].push_back(a);
            in[a]++;
        }

        //拓扑排序
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
                ret.push_back(i);                // 先将入度为 0 的点加入队列和结果中
            }
        }

        // BFS
        while (q.size())
        {
            auto t = q.front();
            q.pop();

            for (auto i : graph[t])
            {
                in[i]--;
                if (in[i] == 0)
                {
                    q.push(i);
                    ret.push_back(i);            // 入度为 0 的点加入队列和结果中
                }
            }
        }

        // 判断是否有环
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i])
            {
                return {};
            }
        }

        return ret;
    }
};