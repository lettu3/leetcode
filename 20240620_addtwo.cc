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

//link to the problem: https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * output = new ListNode();
        ListNode * aux = output;
        ListNode * aux1 = l1;
        ListNode * aux2 = l2;
        int carry = 0;
        int sum_result = 0;
        int val1 = l1->val;
        int val2 = l2->val;

        while (aux1 != NULL || aux2 != NULL || carry > 0){
            if (aux1 != NULL && aux2 != NULL){
                val1 = aux1->val;
                val2 = aux2->val;
            }
            else if (aux1 == NULL && aux2 != NULL){
                val1 = 0;
                val2 = aux2->val;
            }
            else if (aux1 != NULL && aux2 == NULL){
                val1 = aux1->val;
                val2 = 0;
            }
            else {
                val1 = 0;
                val2 = 0;
            }

            sum_result = (val1 + val2) + carry;

            if (sum_result > 9) {
                sum_result = sum_result - 10;
                carry = 1;

            }
            else{
                carry = 0;
            }

            if (aux1 != NULL){
                aux1 = aux1->next;
            }
            if (aux2 != NULL){
                aux2 = aux2->next;
            }

            aux->val = sum_result;

            if (aux1!= NULL || aux2 != NULL || carry > 0){
                aux->next = new ListNode();
                aux = aux->next;
            }    

        }

        return output;
    }
};
