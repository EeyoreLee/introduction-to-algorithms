/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> heapq([](ListNode *a, ListNode *b)
                                                                                                     { return a->val > b->val; });
        for (auto i : lists)
        {
            if (i != nullptr)
            {
                heapq.push(i);
            }
        }
        while (!heapq.empty())
        {
            ListNode *n = heapq.top();
            p->next = n;
            heapq.pop();
            if (n->next != nullptr)
            {
                heapq.push(n->next);
            }
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end
