//力扣：24. 两两交换链表中的节点
//链接：https://leetcode.cn/problems/swap-nodes-in-pairs/description/


//方法：模拟
//算法原理：画图理解
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;                            // 如果链表为空或只有一个节点，直接返回
        }

        ListNode* newhead = new ListNode(0);        // 创建虚拟头节点，简化边界处理
        newhead->next = head;                       // 将虚拟头节点的 next 指向原链表的头节点

        ListNode* prev = newhead, * cur = prev->next, * next = cur->next, * nnext = next->next;

        while (cur && next)                         // 只要 cur 和 next 都不为空，就继续交换
        {
            // 交换节点
            prev->next = next;                      // prev 的 next 指向 next 节点
            next->next = cur;                       // next 的 next 指向 cur 节点
            cur->next = nnext;                      // cur 的 next 指向 nnext，继续遍历下一个节点对

            // 更新指针
            prev = cur;                             // prev 指向当前交换后链表的最后一个节点（cur）
            cur = nnext;                            // cur 指向下一个待交换的节点
            if (cur)                                // 如果 cur 不为空，更新 next
            {
                next = cur->next;
            }
            if (next)                               // 如果 next 不为空，更新 nnext
            {
                nnext = next->next;
            }
        }

        cur = newhead->next;                        // 返回交换后的链表头节点
        delete newhead;                             // 删除虚拟头节点
        return cur;
    }
};