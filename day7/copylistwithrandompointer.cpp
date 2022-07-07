class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        map<Node*,Node*> newList;
        Node *tempHead = head,*newHead = new Node(head->val),*tempNewHead = newHead;
        while(tempHead)
        {
            newList[tempHead] = tempNewHead;
            if(tempHead->next)
            {
                tempNewHead -> next = new Node(tempHead->next->val);    
            }
            
            tempHead = tempHead->next;
            tempNewHead = tempNewHead->next;
        }
        
        tempHead = head;
        tempNewHead = newHead;
        while(tempHead)
        {
            tempNewHead->random = newList[tempHead->random];
            tempNewHead = tempNewHead->next;
            tempHead = tempHead->next;
        }
        
        return newHead;
    }
};