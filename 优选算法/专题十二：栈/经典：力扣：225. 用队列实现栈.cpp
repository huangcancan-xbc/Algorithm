//力扣：225. 用队列实现栈
//https://leetcode.cn/problems/implement-stack-using-queues/description/


class MyStack {
public:
    queue<int> queue1, queue2;                          // 定义两个队列，queue1 和 queue2

    // 构造函数初始化两个队列
    MyStack()
    {

    }

    /*
    压入元素到栈顶：
    1. 将新元素入队到 queue2 中
    2. 将 queue1 中所有元素依次转移到 queue2，确保新元素位于队头（栈顶）
    3. 交换 queue1 和 queue2，使 queue1 始终保存栈的顺序
    */
    void push(int x)
    {
        queue2.push(x);                                 // 新元素入队到 queue2
        while (!queue1.empty())
        {
            queue2.push(queue1.front());                // 将 queue1 元素转移到 queue2
            queue1.pop();
        }
        swap(queue1, queue2);                           // 交换 queue1 和 queue2
    }

    /*
    弹出栈顶元素：
    1. 直接弹出 queue1 队首元素，因为它代表栈顶
    */
    int pop()
    {
        int ret = queue1.front();                       // 获取 queue1 队首元素，即栈顶元素
        queue1.pop();                                   // 弹出队首元素
        return ret;
    }

    /*
    获取栈顶元素：
    1. 返回 queue1 的队首元素，即栈顶
    */
    int top()
    {
        return queue1.front();
    }

    /*
    判断栈是否为空：
    1. 队列 queue1 为空即表示栈为空
    */
    bool empty()
    {
        return queue1.empty();
    }
};

/**
 * 示例用法：
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */






class MyStack {
public:
    queue<int> que;                                 // 定义一个队列 que 用于实现栈的功能

    // 构造函数初始化队列
    MyStack()
    {

    }

    /*
    压入元素到栈顶：
    1. 将元素 x 入队到 que 中
    */
    void push(int x)
    {
        que.push(x);
    }

    /*
    弹出栈顶元素：
    1. 计算队列大小 n 减去 1，得到除栈顶元素外的元素个数
    2. 将前 n 个元素依次出队再入队，以实现将栈顶元素移动到队列开头
    3. 弹出队列开头元素（即栈顶元素），并返回它
    */
    int pop()
    {
        int n = que.size() - 1;                     // 计算要移动的元素个数
        while (n--)
        {
            que.push(que.front());                  // 将队首元素移动到队尾
            que.pop();                              // 弹出队首元素
        }

        int ret = que.front();                      // 获取队首元素，即栈顶元素
        que.pop();                                  // 弹出队首元素
        return ret;
    }

    /*
    获取栈顶元素：
    1. 因为最后压入的元素始终位于队尾，所以直接返回队尾元素
    */
    int top()
    {
        return que.back();
    }

    /*
    判断栈是否为空：
    1. 队列为空即表示栈为空
    */
    bool empty()
    {
        return que.empty();
    }
};

/**
 * 示例用法：
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */








//C语言实现：
#define MAX_SIZE 100                                        // 队列的最大容量

 // 定义循环队列结构体
typedef struct
{
    int data[MAX_SIZE];
    int front, rear;                                        // front指向队头索引，rear指向队尾索引
} Queue;

// 队列的基本操作
void queueInit(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

bool queueIsEmpty(Queue* queue)
{
    return queue->front == queue->rear;
}

bool queueIsFull(Queue* queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue* queue, int value)
{
    if (!queueIsFull(queue))
    {
        queue->data[queue->rear] = value;                   // 将元素放入队尾
        queue->rear = (queue->rear + 1) % MAX_SIZE;         // rear循环递增
    }
}

int dequeue(Queue* queue)
{
    if (!queueIsEmpty(queue))
    {
        int value = queue->data[queue->front];              // 保存队头元素
        queue->front = (queue->front + 1) % MAX_SIZE;       // front循环递增
        return value;
    }
    return -1;                                              // 若队列为空，返回-1
}

int queueFront(Queue* queue)
{
    return queueIsEmpty(queue) ? -1 : queue->data[queue->front];
}

// 定义MyStack结构体，使用两个循环队列来模拟栈
typedef struct
{
    Queue queue1;
    Queue queue2;
} MyStack;

// 栈的操作函数
MyStack* myStackCreate()
{
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&(stack->queue1));
    queueInit(&(stack->queue2));

    return stack;
}

// 将元素 x 压入栈中
void myStackPush(MyStack* obj, int x)
{
    enqueue(&(obj->queue2), x);                             // 新元素先进入queue2

    // 将queue1中的所有元素移动到queue2中
    while (!queueIsEmpty(&(obj->queue1)))
    {
        enqueue(&(obj->queue2), dequeue(&(obj->queue1)));
    }

    // 交换queue1和queue2，使queue1始终保持栈的顺序
    Queue temp = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = temp;
}

// 弹出栈顶元素
int myStackPop(MyStack* obj)
{
    return dequeue(&(obj->queue1));                         // queue1的队头即为栈顶
}

// 获取栈顶元素
int myStackTop(MyStack* obj)
{
    return queueFront(&(obj->queue1));                      // 返回queue1的队头元素
}

// 判断栈是否为空
bool myStackEmpty(MyStack* obj)
{
    return queueIsEmpty(&(obj->queue1));
}

// 释放栈的资源
void myStackFree(MyStack* obj)
{
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */