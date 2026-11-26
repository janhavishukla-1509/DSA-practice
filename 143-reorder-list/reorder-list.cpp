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
    void reorderList(ListNode* head) { //O(N)
        // stack<ListNode*> s;
        // ListNode* temp = head;
        // if(!head || !head->next) return;
        // while(temp != NULL){
        //     s.push(temp);
        //     temp = temp->next;
        // }
        // int n = s.size();
        // ListNode* curr = head;
        // ListNode* nextNode = NULL;
        // for(int i = 0; i < n/2; i++){
        //     nextNode = curr->next;
        //     ListNode* topNode = s.top();
        //     s.pop();
        //     curr->next = topNode;
            
        //     topNode->next = nextNode;
        //     curr = nextNode;
        // }
        // curr->next = NULL;

        // //slow-fast approach gives O(1)
        // //1.find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //2.reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        while(curr != NULL){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        //3.merge first half and reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};