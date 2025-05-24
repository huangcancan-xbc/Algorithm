// 力扣：232. 用栈实现队列
// https://leetcode.cn/problems/implement-queue-using-stacks/description/


class MyQueue {
public:
    stack<int> in;                      // 输入栈，用于接收新元素
    stack<int> out;                     // 输出栈，用于按顺序取出队列元素

    MyQueue()
    {
        // 构造函数，初始化两个栈
    }

    void push(int x)
    {
        in.push(x);                     // 将元素压入输入栈
    }

    int pop()
    {
        // 当输出栈为空时，将输入栈中的元素全部移到输出栈中
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());    // 将输入栈的顶元素移到输出栈
                in.pop();              // 移动后从输入栈弹出
            }
        }

        int ret = out.top();           // 获取输出栈的顶元素，即队首元素
        out.pop();                     // 弹出队首元素
        return ret;
    }

    int peek()
    {
        int ret = this->pop();         // 获取队首元素，通过pop操作得到
        out.push(ret);                 // 由于pop操作移除了队首，这里重新将其放回输出栈
        return ret;
    }

    bool empty()
    {
        return (in.empty() && out.empty());  // 当两个栈均为空时，队列为空
    }
};

/**
 * 示例用法：
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */









// C语言实现：
 // 定义队列结构体
typedef struct {
    int stackInTop, stackOutTop;   // stackInTop 和 stackOutTop 分别表示输入栈和输出栈的栈顶指针
    int stackIn[100], stackOut[100]; // 输入栈和输出栈的数组
} MyQueue;

/*
创建并初始化队列：
1. 为队列分配内存空间
2. 初始化栈顶指针 stackInTop 和 stackOutTop 为 0，表示栈为空
3. 返回创建的队列
*/
MyQueue* myQueueCreate()
{
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->stackInTop = 0;
    queue->stackOutTop = 0;
    return queue;
}

/*
将元素压入队列尾部（使用输入栈）：
1. 将元素 x 存入 stackIn 数组中
2. 栈顶指针 stackInTop 增加 1
*/
void myQueuePush(MyQueue* obj, int x)
{
    obj->stackIn[(obj->stackInTop)++] = x;
}

/*
弹出队列头部元素：
1. 如果输出栈为空，则将输入栈中的所有元素依次转移到输出栈
2. 将输出栈栈顶元素（即队列头部元素）弹出并保存
3. 将输出栈中的剩余元素依次转回输入栈
4. 返回队列头部元素
*/
int myQueuePop(MyQueue* obj)
{
    int stackInTop = obj->stackInTop;        // 复制栈顶指针以减少对内存的访问次数
    int stackOutTop = obj->stackOutTop;

    // 若输出栈为空，则将输入栈元素转移到输出栈
    if (stackOutTop == 0)
    {
        while (stackInTop > 0)
        {
            obj->stackOut[stackOutTop++] = obj->stackIn[--stackInTop];
        }
    }

    // 从输出栈弹出栈顶元素并保存
    int top = obj->stackOut[--stackOutTop];

    // 将输出栈剩余元素转回输入栈
    while (stackOutTop > 0)
    {
        obj->stackIn[stackInTop++] = obj->stackOut[--stackOutTop];
    }

    // 更新栈顶指针
    obj->stackInTop = stackInTop;
    obj->stackOutTop = stackOutTop;

    return top; // 返回队列头部元素
}

/*
获取队列头部元素（不弹出）：
直接返回输入栈的栈底元素，因为它是最先入队的元素
*/
int myQueuePeek(MyQueue* obj)
{
    return obj->stackIn[0];
}

/*
检查队列是否为空：
若两个栈的栈顶指针都为 0，则队列为空
*/
bool myQueueEmpty(MyQueue* obj)
{
    return obj->stackInTop == 0 && obj->stackOutTop == 0;
}

/*
释放队列：
将栈顶指针置 0，以便队列重置
*/
void myQueueFree(MyQueue* obj)
{
    obj->stackInTop = 0;
    obj->stackOutTop = 0;
}
