/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *low = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            low = low->next;
            fast = fast->next->next;
            if (low == fast)
            {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }
        ListNode *init = head;
        while (fast != init)
        {
            init = init->next;
            fast = fast->next;
        }
        return init;
    }
};
// @lc code=end
