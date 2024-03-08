/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k <= 1)
        {
            return head;
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 1; i < k; i++)
        {
            if (p2 != nullptr && p2->next != nullptr)
            {
                p2 = p2->next;
            }
            else
            {
                return head;
            }
        }
        ListNode *tail = p2->next;
        tail = reverseKGroup(tail, k);
        p2->next = nullptr;
        p2 = reverseList(p1);
        p1->next = tail;
        return p2;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *tail = head->next;
        tail = reverseList(tail);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    };
};
// @lc code=end
