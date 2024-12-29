//力扣：2. 两数相加
//链接：https://leetcode.cn/problems/add-two-numbers/description/


//方法：链表
//算法原理：
//画图画图画图，重要的事情说三遍~
//1. 找中间节点；
//2. 中间部分往后的逆序；
//3. 合并两个链表
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* cur1 = l1, * cur2 = l2;
        ListNode* newhead = new ListNode(0);        // 虚拟头节点，用于简化链表操作
        ListNode* prev = newhead;                   // prev 用于跟踪链表的当前尾部
        int t = 0;                                  // 用于保存每位相加的结果及进位

        while (cur1 || cur2 || t)                   // 遍历两个链表，直到所有节点都处理完
        {
            if (cur1)
            {
                t += cur1->val;                     // 如果 cur1 存在，累加其值到 t
                cur1 = cur1->next;                  // 移动到下一个节点
            }
            if (cur2)
            {
                t += cur2->val;                     // 如果 cur2 存在，累加其值到 t
                cur2 = cur2->next;                  // 移动到下一个节点
            }

            prev->next = new ListNode(t % 10);      // 创建新节点，并将当前值 (个位) 加入链表
            prev = prev->next;                      // 移动 prev 指针到新节点
            t /= 10;                                // 更新 t，得到进位
        }

        return newhead->next;                       // 返回去除虚拟头节点后的链表
        // 或者换成：
        //prev=newhead->next;                       // 移动 prev 指针到链表头部
        //delete newhead;                           // 删除虚拟头节点
        //return prev;                              // 返回链表头部
    }
};