//力扣：21. 合并两个有序链表
//https://leetcode.cn/problems/merge-two-sorted-lists/description/



//方法：递归
//算法原理：
//1. 递归函数的含义：交给你两个链表的头结点，你帮我把它们合并起来，并且返回合并后的头结点；
//2. 函数体：选择两个头结点中较⼩的结点作为最终合并后的头结点，然后将剩下的链表交给递归函数去处理；
//3. 递归出⼝：当某⼀个链表为空的时候，返回另外⼀个链表。
//注意注意注意：链表的题⼀定要画图，搞清楚指针的操作！

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;                     // 节点的值
 *     ListNode *next;              // 指向下一个节点的指针
 *     ListNode() : val(0), next(nullptr) {}          // 默认构造函数
 *     ListNode(int x) : val(x), next(nullptr) {}     // 构造函数，初始化值
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}  // 构造函数，初始化值和下一个节点指针
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == NULL)
        {
            return list2;            // 如果 list1 为空，直接返回 list2
        }

        if (list2 == NULL)
        {
            return list1;            // 如果 list2 为空，直接返回 list1
        }

        if (list1->val <= list2->val)
        {
            // 当前 list1 的值较小，将 list1 的下一个节点和 list2 继续合并
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;            // 返回当前的 list1 作为合并后的头结点
        }
        else
        {
            // 当前 list2 的值较小，将 list1 和 list2 的下一个节点继续合并
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;            // 返回当前的 list2 作为合并后的头结点
        }
    }
};
