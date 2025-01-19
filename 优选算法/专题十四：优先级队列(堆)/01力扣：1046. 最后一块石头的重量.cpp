//力扣：1046. 最后一块石头的重量
//链接：https://leetcode.cn/problems/last-stone-weight/description/


//方法：堆（优先队列）

//算法原理：
//其实就是⼀个模拟的过程：
//• 每次从⽯堆中拿出最⼤的元素以及次⼤的元素，然后将它们粉碎；
//• 如果还有剩余，就将剩余的⽯头继续放在原始的⽯堆⾥⾯
//重复上⾯的操作，直到⽯堆⾥⾯只剩下⼀个元素，或者没有元素（因为所有的⽯头可能全部抵消了）
//
//那么主要的问题就是解决：
//• 如何顺利的拿出最⼤的⽯头以及次⼤的⽯头；
//• 并且将粉碎后的⽯头放⼊⽯堆中之后，也能快速找到下⼀轮粉碎的最⼤⽯头和次⼤⽯头；
//
//这不正好可以利⽤堆的特性来实现嘛？
//• 我们可以创建⼀个⼤根堆；
//• 然后将所有的⽯头放⼊⼤根堆中；
//• 每次拿出前两个堆顶元素粉碎⼀下，如果还有剩余，就将剩余的⽯头继续放⼊堆中；
//这样就能快速的模拟出这个过程。
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> heap;                   // 创建一个⼤根堆
        for (auto x : stones)
        {
            heap.push(x);                           // 将所有的⽯头放⼊⼤根堆中
        }

        while (heap.size() > 1)                     // 只要堆中有两个元素，就一直循环
        {
            // 分别拿出最⼤的⽯头以及次⼤的⽯头
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();

            if (a > b)                              // a 比 b 先拿，所以一定 a >= b,将 a - b （一定是正数）放⼊堆中
            {
                heap.push(a - b);
            }
        }

        return heap.size() ? heap.top() : 0;        // 如果堆中只剩下⼀个元素，则返回它，否则返回 0
    }
};