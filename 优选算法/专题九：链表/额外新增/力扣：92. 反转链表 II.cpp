// 力扣：92. 反转链表 II
// 链接：https://leetcode.cn/problems/reverse-linked-list-ii/description/

// 方法：链表、模拟
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left >= right)
        {
            return head;
        }

        // 新的头
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;

        // left节点前一个指针,以及right节点后一个指针
        ListNode* ll = new_head, * rr = nullptr;
        for (int i = 0; i < left - 1; i++)
        {
            ll = ll->next;
        }
        // 暂存left节点，反转后会变成尾用于拼接
        ListNode* ll_next = ll->next;

        rr = ll_next;   // 从left出发
        for (int i = 0; i < right - left + 1; i++)
        {
            rr = rr->next;
        }

        // 反转指定区域，反转后的pre就是反转链表的头
        ListNode* pre = nullptr, * cur = ll->next;  // cur要从left出发
        while (cur != rr)
        {
            ListNode* next;
            next = cur->next;   // 先保存下一个节点
            cur->next = pre;    // 反转，将当前节点指针指向前一个
            pre = cur;          // 反转完pre往后走进行更新，准备处理下一个节点
            cur = next;         // cur也随之更新
        }

        // 拼接链表
        ll->next = pre;         // left前一个节点连接反转链表的头pre
        ll_next->next = rr;     // 反转链表的尾连接right的下一个节点

        return new_head->next;
    }
};