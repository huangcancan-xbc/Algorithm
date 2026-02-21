// 力扣：143. 重排链表
// 链接：https://leetcode.cn/problems/reorder-list/description/

// 方法一：用数组简化交叉连接
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
    void reorderList(ListNode* head)
    {
        vector<ListNode*> v;
        ListNode* new_head = head;
        while (new_head)
        {
            v.emplace_back(new_head);
            new_head = new_head->next;
        }

        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            // 交叉连接（指向）
            v[i++]->next = v[j];
            if (i == j)
            {
                break;
            }
            v[j--]->next = v[i];
        }

        v[i]->next = nullptr;   // 别忘记链表最后指向空
    }
};




// 方法二：快慢指针找中点，将链表分成两段，并将后半段链表反转，最后合并
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
    void reorderList(ListNode* head)
    {
        // 快慢指针找中点
        ListNode* left = head, * right = head;
        while (right->next && right->next->next)
        {
            left = left->next;
            right = right->next->next;
        }
        // 注意先保存前半段，再将后半段链表进行断开
        ListNode* cur = left->next;
        left->next = nullptr;

        ListNode* prev = nullptr, * temp = nullptr;
        while (cur)
        {
            temp = cur->next;  // 暂存下一个节点
            cur->next = prev;  // 反转链表
            prev = cur;        // 准备处理下一个节点
            cur = temp;        // 同样更新当前节点，准备处理下一个
        }

        // 合并链表
        while (head && prev)
        {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = prev->next;
            head->next = prev;
            prev->next = tmp1;
            head = tmp1;
            prev = tmp2;
        }
    }
};