/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next==nullptr && n==1) {
            return nullptr;
        }
        ListNode* left_pr = head;
        ListNode* right_pr = head;
        for (int i=0; i<n; i++) {
            if (right_pr==nullptr){
                return head;
            }
            right_pr = right_pr->next;
        }
        if (right_pr==nullptr) {
            return head->next;
        }
        while(right_pr->next!=nullptr) {
            left_pr = left_pr->next;
            right_pr = right_pr->next;
        }
        left_pr->next = left_pr->next->next;
        return head;
    }
};
// @lc code=end

