/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        int q, r = 0, v1, v2;
        while (p1 != nullptr || p2 != nullptr)
        {
            v1 = (p1 != nullptr && p1->val) ? p1->val : 0;
            v2 = (p2 != nullptr && p2->val) ? p2->val : 0;
            q = (v1 + v2 + r) % 10;
            ListNode *t = new ListNode(q);
            r = (v1 + v2 + r) > 9 ? 1 : 0;
            p->next = t;
            p = p->next;
            p1 = p1 != nullptr ? p1->next : nullptr;
            p2 = p2 != nullptr ? p2->next : nullptr;
        }
        if (r != 0)
        {
            ListNode *t = new ListNode(r);
            p->next = t;
        }
        return dummy->next;
    }
};
// @lc code=end
