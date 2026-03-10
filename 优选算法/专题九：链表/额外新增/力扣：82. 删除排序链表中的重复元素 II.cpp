// 力扣：82. 删除排序链表中的重复元素 II
// 链接：https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/

// 方法：链表
// 思路：直接模拟比较，每次只看后面2个，如果值一样说明重复，记下这个值并跳过后面值相同的节点
// 如果值不一样，直接往后走并进行链接，得出结果
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)
        {
            return head;
        }

        // 新的头节点
        ListNode* new_head = new ListNode(0);
        new_head->next = head;

        // 指针节点
        ListNode* cur = new_head;
        while (cur->next && cur->next->next)
        {
            // 如果后面2个节点值一样
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                // 后面的节点有效并且值相等就一直往后走
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else    // 反之直接链接加入
            {
                cur = cur->next;
            }
        }

        return new_head->next;
    }
};