/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
#include <queue>
class Solution {
public:
    struct tmp
    {
        bool operator()(ListNode* a, ListNode* b) const {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* dynamic_head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, tmp> q;
        for (auto i: lists) {
            if (i!=nullptr) {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            auto v = q.top();
            q.pop();
            dynamic_head->next = v;
            dynamic_head = dynamic_head->next;
            if (v->next!=nullptr) {
                q.push(v->next);
            }
        }
        return dummy->next;
    }
};
// @lc code=end

