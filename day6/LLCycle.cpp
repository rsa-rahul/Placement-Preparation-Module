class Solution {
public:
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next)   return NULL;   
    ListNode *s=head, *f=head, *st=head;
    while(f->next && f->next->next)
    {
        s = s->next;
        f = f->next->next;
        if(s==f)
        {
            while(s != st)
            {
                s = s->next;
                st = st->next;
            }
            return st;
        }
    }
    return NULL;
}
};