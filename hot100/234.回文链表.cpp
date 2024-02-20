/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
#include <stdio.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *low = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            low = low->next;
            fast = fast->next->next;
        }
        low = reverseList(low);
        ListNode *init = head;
        while (low != nullptr)
        {
            if (low->val != init->val)
            {
                return false;
            }
            cout << low->val << endl;
            low = low->next;
            init = init->next;
        }
        return true;
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
    }
};
// @lc code=end
