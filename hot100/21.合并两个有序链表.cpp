/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        if (list2 == nullptr)
        {
            return list1;
        }
        ListNode *n1 = list1;
        ListNode *n2 = list2;
        ListNode *r;
        if (n1->val <= n2->val)
        {
            r = n1;
            n1 = n1->next;
        }
        else
        {
            r = n2;
            n2 = n2->next;
        }
        ListNode *p = r;
        while (n1 != nullptr && n2 != nullptr)
        {
            if (n1->val <= n2->val)
            {
                r->next = n1;
                n1 = n1->next;
                r = r->next;
            }
            else
            {
                r->next = n2;
                n2 = n2->next;
                r = r->next;
            }
        }
        if (n1 != nullptr)
        {
            r->next = n1;
        }
        if (n2 != nullptr)
        {
            r->next = n2;
        }
        return p;
    }
};
// @lc code=end
