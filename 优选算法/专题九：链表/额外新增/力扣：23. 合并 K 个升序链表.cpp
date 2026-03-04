// 力扣：23. 合并 K 个升序链表
// 链接：https://leetcode.cn/problems/merge-k-sorted-lists/description/

// 方法一：链表
// 思路：把链表的值全部加入到一个临时数组中，对这个数组进行排序，新创建一个链表，将数组的每一个值构造成链表节点进行连接，返回结果
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // 1. 创建数组，并将全部链表的值加入数组
        vector<int> value;
        for (auto list : lists)
        {
            while (list)
            {
                value.push_back(list->val);
                list = list->next;
            }
        }

        // 2. 对链表进行排序
        sort(value.begin(), value.end());

        // 3. 创建链表，将数组的每一个值构造成链表节点进行连接
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        for (int i = 0; i < value.size(); i++)
        {
            cur->next = new ListNode(value[i]);
            cur = cur->next;
        }

        return head->next;      // 4. 返回节点的头
    }
};



// 方法二：逐个比较
// 思路：因为每个链表都已经按升序排列，我们可以先将每个链表的头加入到一个小根堆中，堆顶即当前最小节点
// 将堆顶的这个最小节点加入到结果链表中，并将堆顶下一个非空节点加入堆中，如此反复即出结果
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // 1. 创建小根堆，并设置比较器（仿函数）
        // 两种写法（个人感觉第一种方便）
        //auto cmp = [](const ListNode* a, const ListNode* b)
        //    {
        //        return a->val > b->val;
        //    };
        //priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q;
        struct cmp
        {
            bool operator()(const ListNode* a, const ListNode* b) const
            {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;

        // 2. 将每一个链表的头加入堆中（注意合法性）
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
            {
                q.push(lists[i]);
            }
        }

        // 3. 谁小弹谁，弹完把它的下一个扔进去
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while (q.size())
        {
            cur->next = q.top();        // 当前最小的节点加入结果
            q.pop();                    // 他最小，用完弹出去
            cur = cur->next;            // 指针后移
            if (cur->next)
            {
                q.push(cur->next);      // 下一个合法的节点入堆
            }
        }

        return head->next;              // 返回结果
    }
};