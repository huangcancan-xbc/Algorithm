//力扣：24. 两两交换链表中的节点
//链接：https://leetcode.cn/problems/swap-nodes-in-pairs/description/


//方法：递归
//
//算法原理：
//1. 递归函数的含义：交给你⼀个链表，将这个链表两两交换⼀下，然后返回交换后的头结点；
//2. 函数体：先去处理⼀下第⼆个结点往后的链表，然后再把当前的两个结点交换⼀下，连接上后⾯处理后的链表；
//3. 递归出⼝：当前结点为空或者当前只有⼀个结点的时候，不⽤交换，直接返回。
//注意注意注意：链表的题⼀定要画图，搞清楚指针的操作！
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        // 1. 如果链表为空或只有一个节点，直接返回头节点，不做交换
        if (head == nullptr || head->next == nullptr) return head;

        // 2. 递归地处理剩余的链表
        auto tmp = swapPairs(head->next->next);  // 递归调用交换后续的链表

        // 3. 交换当前节点和下一个节点
        auto ret = head->next;                   // ret指向交换后的节点
        head->next->next = head;                 // 当前节点与下一个节点交换
        head->next = tmp;                        // 当前节点的下一个节点指向递归处理后的链表

        // 4. 返回交换后的新头节点
        return ret;
    }
};
