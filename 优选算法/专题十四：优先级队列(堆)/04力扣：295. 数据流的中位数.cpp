//力扣：295. 数据流的中位数
//链接：https://leetcode.cn/problems/find-median-from-data-stream/description/



//方法一：排序

//算法原理：每次排完序后，如果数组长度是偶数，则中间两个数的平均值就是中位数；如果数组长度是奇数，则中间数就是中位数。
//每次调用addNum都需要对数组排序，时间复杂度为 O(nlogn)，空间复杂度为 O(1)。所以会超时。
class MedianFinder 
{
public:
    vector<int> v;                                          // 存储数据的容器，始终保持有序
    MedianFinder() 
    {

    }

    void addNum(int num)
    {
        v.push_back(num);                                   // 每次向容器中插入一个元素，并进行排序
        sort(v.begin(), v.end());
    }

    double findMedian()
    {
        int n = v.size();
        if (n % 2 == 0)
        {
            return (v[n / 2 - 1] + v[n / 2]) / 2.0;         // 如果元素个数是偶数，中位数是中间两个数的平均值
        }
        else
        {
            return v[n / 2];                                // 如果元素个数是奇数，中位数是中间的那个数
        }
    }
};




//方法二：插入排序

//算法原理：通过插入排序的思想，我们可以在插入新元素时，将其直接插入到正确的位置，
//从而保持容器始终是有序的。这样可以避免每次插入后再进行整体排序，从而提升效率。
class MedianFinder
{
public:
    vector<int> v;                                          // 存储数据的容器，始终保持有序
    MedianFinder()
    {

    }

    void addNum(int num) 
    {
        auto it = lower_bound(v.begin(), v.end(), num);     // 使用二分查找找到插入位置，保持数组有序
        v.insert(it, num);                                  // 在正确的位置插入元素
    }

    double findMedian() 
    {
        int n = v.size();
        if (n % 2 == 0) 
        {
            return (v[n / 2 - 1] + v[n / 2]) / 2.0;         // 如果元素个数是偶数，中位数是中间两个数的平均值
        }
        else 
        {
            return v[n / 2];                                // 如果元素个数是奇数，中位数是中间的那个数
        }
    }
};
//lower_bound:
//如果数组中已存在，则返回一个指向第一次出现的 num 的迭代器。
//如果数组中不存在,该函数仍将返回一个迭代器，指向应该插入的位置，以保持排序顺序。
//这使得它可以安全地使用，因为 will 处理在正确位置插入值。




//方法三：使用两个堆

//算法原理见 04 算法原理.png
class MedianFinder
{
public:
    priority_queue<int> left;                               // 左堆，存放较小的一半数据
    priority_queue<int, vector<int>, greater<int>> right;   // 右堆，存放较大的一半数据

    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if (left.size() == right.size())
        {
            if (left.empty() || num <= left.top())          // 如果左堆为空，或者新元素小于等于左堆的堆顶，则插入左堆
            {
                left.push(num);
            }
            else                                            // 如果新元素大于左堆的堆顶，则插入右堆
            {
                right.push(num);
                left.push(right.top());                     // 将右堆的堆顶（最小值）插入左堆，保证左堆元素多一个
                right.pop();                                // 弹出右堆的堆顶元素
            }
        }
        else                                                // 如果左堆的元素数量多于右堆
        {
            if (num <= left.top())                          // 如果新元素小于等于左堆的堆顶
            {
                left.push(num);
                right.push(left.top());                     // 将左堆的堆顶（最大值）插入右堆
                left.pop();                                 // 弹出左堆的堆顶元素
            }
            else
            {
                right.push(num);                            // 如果新元素大于左堆的堆顶,直接插入右堆
            }
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;        // 如果两个堆的元素数量相等，中位数是两个堆顶的平均值
        }
        else
        {
            return left.top();                              // 如果左堆的元素数量多，中位数是左堆的堆顶
        }
    }
};