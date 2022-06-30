/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dynamic_a = headA;
        ListNode* dynamic_b = headB;
        while(dynamic_a!=dynamic_b) {
            if (dynamic_a==nullptr) {
                dynamic_a = headB;
            }
            else {
                dynamic_a = dynamic_a->next;
            }
            if (dynamic_b==nullptr) {
                dynamic_b = headA;
            }
            else {
                dynamic_b = dynamic_b->next;
            }
        }
        return dynamic_a;
    }
};
// @lc code=end

