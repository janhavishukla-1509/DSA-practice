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
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        if(h1 == NULL || h2 == NULL){
            return NULL;
        }
        ListNode* temp1 = h1;
        ListNode* temp2 = h2;
        while(temp1 != temp2){
            temp1 = (temp1 == NULL) ? h2 : temp1->next;
            temp2 = (temp2 == NULL) ? h1 : temp2->next;
        }
        return temp1;
    }
};