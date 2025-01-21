//力扣：692. 前K个高频单词
//链接：https://leetcode.cn/problems/top-k-frequent-words/description/


//方法：哈希表+堆 

//算法原理：
//• 稍微处理⼀下原数组：
//    a.我们需要知道每⼀个单词出现的频次，因此可以先使⽤哈希表，统计出每⼀个单词出现的频次；
//    b.然后在哈希表中，选出前 k ⼤的单词
//    （为什么不在原数组中选呢？因为原数组中存在重复的单词，哈希表⾥⾯没有重复单词，并且还有每⼀个单词出现的频次）
//• 如何使⽤堆，拿出前 k ⼤元素：
//    a.先定义⼀个⾃定义排序，我们需要的是前 k ⼤，因此需要⼀个⼩根堆。但是当两个字符串的频次相同的时候，
//    我们需要的是字典序较⼩的，此时是⼀个⼤根堆的属性，在定义⽐较器的时候需要注意！
//        ▪ 当两个字符串出现的频次不同的时候：需要的是基于频次⽐较的⼩根堆
//        ▪ 当两个字符串出现的频次相同的时候：需要的是基于字典序⽐较的⼤根堆
//    b.定义好⽐较器之后，依次将哈希表中的字符串插⼊到堆中，维持堆中的元素不超过 k 个；
//    c.遍历完整个哈希表后，堆中的剩余元素就是前 k ⼤的元素
class Solution 
{
public:
    typedef pair<string, int> PSI;

    struct cmp                                                  // 定义比较器，用于在优先队列中排序
    {
        bool operator()(const PSI& a, const PSI& b)
        {
            if (a.second == b.second)                           // 如果频次相同，按字典顺序排序
            {
                return a.first < b.first;                       // 字典顺序升序排列
            }

            return a.second > b.second;                         // 否则按频次降序排列
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k)
    {
        // 遍历输入的单词列表，统计每个单词的出现次数
        unordered_map<string, int> hash;
        for (auto x : words)
        {
            hash[x]++;
        }

        priority_queue<PSI, vector<PSI>, cmp> heap;             // 最大堆，按频次排序

        for (auto& x : hash)                                    // 遍历哈希表，将每个单词和频次插入堆中
        {
            heap.push(x);                                       // 将单词和频次推入堆
            if (heap.size() > k)
            {
                heap.pop();                                     // 如果堆的大小超过 k，弹出堆顶元素
            }
        }

        vector<string> ret(k);

        // 从堆中取出 k 个最频繁的单词
        for (int i = k - 1; i >= 0; i--)
        {
            ret[i] = heap.top().first;
            heap.pop();
        }

        return ret;
    }
};
//自定义全局比较规则
//定义的比较结构体
//注意：cmp是个结构体 
//struct cmp //自定义堆的排序规则 
//{
//    bool operator()(const Point& a, const Point& b) 
//    {
//        return a.x < b.x;
//    }
//};
//
//初始化定义， 
//priority_queue<Point, vector<Point>, cmp> q; // x大的在堆顶