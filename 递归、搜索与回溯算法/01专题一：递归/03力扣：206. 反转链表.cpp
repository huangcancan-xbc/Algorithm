//力扣：206. 反转链表
//https://leetcode.cn/problems/reverse-linked-list/description/


//方法一：双指针法

//算法原理：
//首先定义一个cur指针，指向头结点，再定义一个pre指针，初始化为null。
//然后就要开始反转了，首先要把 cur->next 节点用tmp指针保存一下，也就是保存一下这个节点。
//为什么要保存一下这个节点呢，因为接下来要改变 cur->next 的指向了，将cur->next 指向pre ，此时已经反转了第一个节点了。
//接下来，就是循环走如下代码逻辑了，继续移动pre和cur指针。
//最后，cur 指针已经指向了null，循环结束，链表也反转完毕了。 此时我们return pre指针就可以了，pre指针就指向了新的头结点。
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr, *cur = head, *tmp;
        //注意：ListNode* prev = nullptr, *cur = head, *tmp; 和 ListNode* prev = nullptr, cur = head, tmp; 不等价
        //ListNode* prev = nullptr, cur = head, tmp; 是错误的，因为 cur 和 tmp 的类型是 ListNode。
        //正确的写法应该是 ListNode* prev = nullptr, *cur = head, *tmp = nullptr;

        while (cur) 
        {
            tmp = cur->next;      // 记录下一个节点，防止丢失
            cur->next = prev;     // 当前节点指向前一个节点（实现反转）
            prev = cur;           // 前驱节点后移到当前节点
            cur = tmp;            // 当前节点后移到下一个节点
        }

        return prev;              // 循环结束时，prev 指向新的头节点
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr, * cur = head, * tmp;

        while (cur) 
        {
            tmp = cur->next;      // 记录下一个节点，防止丢失
            cur->next = prev;     // 当前节点指向前一个节点（实现反转）
            prev = cur;           // 前驱节点后移到当前节点
            cur = tmp;            // 当前节点后移到下一个节点
        }

        return prev;              // 循环结束时，prev 指向新的头节点
    }
};





//方法二：递归法

class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) 
    {
        if (cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) 
    {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};


//递归模拟从尾部反转
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        // 递归终止条件：当前节点为空或是最后一个节点
        if (!head || !head->next)                   // if (head ==  nullptr || head->next == nullptr)
        {
            return head;
        }

        // 递归反转子链表
        ListNode* newHead = reverseList(head->next);

        // 当前节点的下一个节点指向当前节点，实现反转
        head->next->next = head;
        head->next = nullptr;                       // 当前节点变成尾节点，指向 nullptr

        return newHead;                             // 返回新头节点
    }
};


//显式使用栈模拟从尾部反转
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head) return nullptr;

        std::stack<ListNode*> nodeStack;
        ListNode* cur = head;

        // 将链表所有节点压入栈
        while (cur)
        {
            nodeStack.push(cur);
            cur = cur->next;
        }

        // 重新构建链表
        ListNode* newHead = nodeStack.top();
        nodeStack.pop();
        cur = newHead;

        while (!nodeStack.empty())
        {
            cur->next = nodeStack.top();
            nodeStack.pop();
            cur = cur->next;
        }

        cur->next = nullptr;                        // 最后一个节点指向 nullptr
        return newHead;
    }
};
