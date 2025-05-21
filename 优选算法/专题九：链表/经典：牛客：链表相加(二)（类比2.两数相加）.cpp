//牛客：链表相加(二)
//链接：https://www.nowcoder.com/share/jump/5170733851734862276831


//方法：链表
class Solution 
{
public:
    ListNode* reverse(ListNode* head)                   // head是指针类型
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode* cur = head;                           // cur应该是指向ListNode的指针
        ListNode* node = nullptr;                       // node也是指向ListNode的指针
        while (cur != nullptr)
        {
            ListNode* tail = cur->next;                 // 用箭头（->）访问成员
            cur->next = node;                           // 改为 cur->next
            node = cur;                                 // 将node指向当前节点
            cur = tail;                                 // 移动到下一个节点
        }

        return node;                                    // 返回反转后的头结点
    }


    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        // 如果任意一个链表为空，则直接返回另一个链表
        if (head1 == nullptr)
        {
            return head2;
        }
        if (head2 == nullptr)
        {
            return head1;
        }

        // 反转链表
        head1 = reverse(head1);
        head2 = reverse(head2);

        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;
        int t = 0;

        while (head1 || head2 || t)
        {
            if (head1)
            {
                t += head1->val;
                head1 = head1->next;
            }
            if (head2)
            {
                t += head2->val;
                head2 = head2->next;
            }

            prev->next = new ListNode(t % 10);
            prev = prev->next;
            t /= 10;
        }

        return reverse(newhead->next);
    }
};



/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution 
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
     // 反转链表
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr)
        {
            ListNode* nextNode = curr->next;            // 保存下一个节点
            curr->next = prev;                          // 当前节点的next指向前一个节点
            prev = curr;                                // 更新prev为当前节点
            curr = nextNode;                            // 移动到下一个节点
        }

        return prev;                                    // 返回新的头结点
    }

    // 两个链表相加
    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        if (!head1) return head2;                       // head1为空，直接返回head2
        if (!head2) return head1;                       // head2为空，直接返回head1

        // 反转链表
        head1 = reverse(head1);
        head2 = reverse(head2);

        ListNode* newHead = new ListNode(0);            // 哨兵节点
        ListNode* prev = newHead;                       // prev指向当前节点
        int carry = 0;                                  // 进位

        // 加法操作，直到两个链表都遍历完并且没有进位
        while (head1 || head2 || carry)
        {
            int sum = carry;                            // 先加上进位

            if (head1)
            {
                sum += head1->val;                      // 加上head1的当前节点值
                head1 = head1->next;                    // 移动到下一个节点
            }

            if (head2)
            {
                sum += head2->val;                      // 加上head2的当前节点值
                head2 = head2->next;                    // 移动到下一个节点
            }

            prev->next = new ListNode(sum % 10);        // 创建新节点，并链接到结果链表
            prev = prev->next;

            carry = sum / 10;                           // 计算进位
        }

        return reverse(newHead->next);                  // 反转结果链表并返回
    }
};