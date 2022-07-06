class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {
ListNode* curr = head;
int count = 0;
while(curr){
curr = curr->next;
count++;
}
if(n > count) return NULL;
if(n == count) return head->next;
n = count - n;
curr = head;
head = curr;
while(--n)
{
curr=curr->next;
}
curr->next = curr->next->next;
return head;
}
};