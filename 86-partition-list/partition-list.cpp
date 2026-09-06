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
        if(head == NULL){
            return head;
        }
        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* lessTail = &lessDummy;
        ListNode* greaterTail = &greaterDummy;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val < x){
                lessTail->next = curr;
                lessTail = lessTail->next;
            }
            else{
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }
        greaterTail->next = NULL;
        lessTail->next = greaterDummy.next;
        return lessDummy.next;
    }
};