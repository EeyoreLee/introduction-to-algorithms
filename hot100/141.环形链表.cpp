/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *low = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            low = low->next;
            fast = fast->next->next;
            if (fast == low)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
