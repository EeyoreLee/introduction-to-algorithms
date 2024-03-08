/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
#include <algorithm>

using namespace std;

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        quickSort(head);
        return head;
    }
    void quickSort(ListNode *head, ListNode *end = nullptr)
    {
        if (head == nullptr || head == end)
        {
            return;
        }
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2 != end)
        {
            if (p2->val < head->val)
            {
                p1 = p1->next;
                swap(p1->val, p2->val);
            }
            p2 = p2->next;
        }
        swap(head->val, p1->val);
        quickSort(head, p1);
        quickSort(p1->next, end);
    }
};
// @lc code=end
