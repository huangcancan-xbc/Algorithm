//力扣：207. 课程表
//链接：https://leetcode.cn/problems/course-schedule/description/


//方法：拓扑排序

//算法原理：
//原问题可以转换成⼀个拓扑排序问题。⽤ BFS 解决拓扑排序即可。
//
//拓扑排序流程：
//a.将所有⼊度为 0 的点加⼊到队列中；
//b.当队列不空的时候，⼀直循环：
//    i.取出队头元素；
//    ii.将于队头元素相连的顶点的⼊度 - 1；
//    iii.然后判断是否减成 0, 。如果减成 0，就加⼊到队列中。
class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, vector<int>> map;        // 邻接表
        vector<int> in(numCourses);                 // 存储每一个节点的入度

        // 1.建图
        for (auto x : prerequisites)
        {
            int a = x[0], b = x[1];                 // b -> a
            map[b].push_back(a);                    // 映射 b -> a，相当于 b 指向 a 的一条边
            in[a]++;                                // a 的入度 + 1
        }
        
        // 2.拓扑排序
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);                          // 将所有入度为 0 的点加⼊到队列中
            }
        }

        // BFS
        while (q.size())
        {
            auto t = q.front();                     // 取出队头元素，并将其出队
            q.pop();

            for (auto x : map[t])
            {
                in[x]--;                            // 修改 x 的入度(相邻的边减 1)
                if (in[x] == 0)
                {
                    q.push(x);                      // 如果 x 的入度减成 0，就加⼊到队列中
                }
            }
        }

        // 3.判断是否有环
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i])
            {
                return false;                       // 如果有入度不为 0 的点，说明有环，返回 false
            }
        }

        return true;
    }
};




//二维数组表示邻接表：
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);      // 邻接表，用二维数组表示
        vector<int> in(numCourses);                 // 存储每个课程的入度

        // 1. 建图
        for (auto& x : prerequisites)
        {
            int a = x[0], b = x[1];                 // b -> a
            graph[b].push_back(a);                  // 将 a 添加到 b 的邻接课程列表中
            in[a]++;                                // a 的入度增加
        }

        // 2. 拓扑排序
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);                          // 将所有入度为 0 的课程加入队列
            }
        }

        // BFS
        while (!q.empty())
        {
            int t = q.front();                      // 获取队头课程
            q.pop();

            // 遍历与当前课程相关的课程（相邻课程）
            for (int x : graph[t])
            {
                in[x]--;                            // 相邻课程的入度减少
                if (in[x] == 0)
                {
                    q.push(x);                      // 如果入度变为 0，将该课程加入队列
                }
            }
        }

        // 3. 判断是否有环
        for (int i = 0; i < numCourses; i++)
        {
            if (in[i] > 0)
            {
                return false;                       // 如果存在入度不为 0 的课程，说明有环
            }
        }

        return true;
    }
};
