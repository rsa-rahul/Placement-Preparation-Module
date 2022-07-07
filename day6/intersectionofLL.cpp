class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB)    return NULL;
    ListNode *h1=headA, *h2=headB;
    while(h1!=h2)
    {
        h1 = !h1 ? headB : h1->next;
        h2 = !h2 ? headA : h2->next;
    }
    return h1;
}
};