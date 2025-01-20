//力扣：703. 数据流中的第 K 大元素
//链接：https://leetcode.cn/problems/kth-largest-element-in-a-stream/description/


//方法：优先级队列

//算法原理：
//本题属于 TOP-K 问题，看到就应该立刻想到「堆」,这应该属于刻在骨子里的记忆。
class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> heap;    // 定义一个小根堆
    int _k;                                                 // 用于记录堆中元素的个数（大小）

public:
    KthLargest(int k, vector<int>& nums)
    {
        // 遍历一遍 nums，将其中的元素加入堆中，并保持堆的大小不超过 k，当堆的大小超过 k 时，弹出堆顶元素
        _k = k;
        for (auto x : nums)
        {
            heap.push(x);
            if (heap.size() > _k)
            {
                heap.pop();
            }
        }
    }

    int add(int val)
    {
        // 将 val 加入堆中，并保持堆的大小不超过 k，当堆的大小超过 k 时，弹出堆顶元素
        heap.push(val);
        if (heap.size() > _k)
        {
            heap.pop();
        }

        return heap.top();                                  // 堆顶元素即为第 k 大元素
    }
};