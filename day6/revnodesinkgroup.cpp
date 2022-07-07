class Solution {
public:
    int lengthOfLL(ListNode* head)
    {
        int length=0;
        while(head!=NULL)
        {
            head=head->next;
            length++;   
        }
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k,int length)
    {
        if(length<k) return head;
        int count=0;
        ListNode*prev=NULL;
        ListNode*c=head;
        ListNode*n=NULL;
        while(c!=NULL && count<k)
        {
            n=c->next;
            c->next=prev;
            prev=c;
            c=n;
            count++;
        }
        //call recursion for remaining node
        if(n!=NULL)
        {
            head->next=reverseKGroup(n,k,length-k);
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
   int length=lengthOfLL(head);
        return reverseKGroup(head,k,length);
        
    }
};