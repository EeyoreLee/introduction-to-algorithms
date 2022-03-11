#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        bool l1Stop = false;
        bool l2Stop = false;
        int l1Val;
        int l2Val;
        int sumRes;
        ListNode *res = new ListNode(-1);
        ListNode *tmp = res;
        if(l1->next!=NULL||l2->next!=NULL){
            std::cout << "11111" << std::endl;
        }
        while(l1->next!=NULL&&l2->next!=NULL){
            l1Val = l1Stop?0:l1->val;
            l2Val = l2Stop?0:l2->val;
            sumRes = l1Val + l2Val;
            if(carry){
                sumRes++;
            };
            // std::cout << sumRes%10 << " ";
            tmp->next = new ListNode(sumRes%10);
            tmp = tmp->next;
            carry = sumRes<10?false:true;
            if(l1->next!=NULL){
                l1 = l1->next;
            }
            else{
                l1Stop = true;
            };
            if(l2->next!=NULL){
                l2 = l2->next;
            }
            else{
                l2Stop = true;
            };
        };
        l1Val = l1Stop?0:l1->val;
        l2Val = l2Stop?0:l2->val;
        sumRes = l1Val + l2Val;
        if(carry){
            sumRes++;
        };
        // std::cout << sumRes%10 << " ";
        tmp->next = new ListNode(sumRes%10);
        tmp = tmp->next;
        carry = sumRes<10?false:true;
        if(carry){
            tmp->next = new ListNode(1);
            // tmp = tmp->next;
        };
        return res->next;
    }
};

int main(){
    int array1[] = {9,9};
    int array2[] = {9};
    ListNode *listNode1 = new ListNode(-1);
    ListNode *tmp1 = listNode1;
    ListNode *listNode2 = new ListNode(-1);
    ListNode *tmp2 = listNode2;
    for(int it:array1){
        tmp1->next = new ListNode(it);
        tmp1 = tmp1->next;
    };
    for(int it:array2){
        tmp2->next = new ListNode(it);
        tmp2 = tmp2->next;
    };
    Solution sol;
    ListNode *res = sol.addTwoNumbers(listNode1->next, listNode2->next);
    do{
        std::cout << res->val << " ";
        res = res->next;
    }while(res->next!=NULL);
    std::cout << res->val << " ";
    std::cout << std::endl;
    return 0;
}