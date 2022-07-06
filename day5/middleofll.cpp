class Solution {
public://rahul
    ListNode* middleNode(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* fast=head, *slow=head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};