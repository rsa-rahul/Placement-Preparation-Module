class Solution {
public:
    ListNode* helper(ListNode* head,ListNode* &prev){
        if(head==NULL)
            return head;
        
        ListNode *next=head->next;
        head->next=prev;
        prev=head;
        return helper(next,prev);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        helper(head,prev);
        return prev;   
    }
};