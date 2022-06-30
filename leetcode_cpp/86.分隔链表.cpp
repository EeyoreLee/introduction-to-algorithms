/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_small = new ListNode(-1);
        ListNode* dummy_big = new ListNode(-1);
        ListNode* dynamic_head_small = dummy_small;
        ListNode* dynamic_head_big = dummy_big;
        while (head!=nullptr)
        {
            if (head->val<x) {
                dynamic_head_small->next = head;
                head = head->next;
                dynamic_head_small = dynamic_head_small->next;
            }
            else {
                dynamic_head_big->next = head;
                head = head->next;
                dynamic_head_big = dynamic_head_big->next;
            }
        }
        dynamic_head_big->next = nullptr;
        dynamic_head_small->next = dummy_big->next; 
        return dummy_small->next;

    }
};
// @lc code=end

