
Node* merge(Node* first , Node* second)
{
   Node* temp = new Node(-1);
   Node* ans = temp;
   
   while(first!=NULL && second!=NULL)
   {
       if(first->data < second->data)
       {
           temp->bottom = first;
           temp = first;
           first = first->bottom;
       }
       
       else
       {
           temp->bottom = second;
           temp = second;
           second = second->bottom;
       }
   }
   
   if(first!=NULL)
   {
        temp->bottom = first;
           temp = first;
           first = first->bottom;
   }
   
   if(second!=NULL)
   {
        temp->bottom = second;
           temp = second;
           second = second->bottom;
   }
   
   ans = ans->bottom;
   return ans;
}

 

Node *flatten(Node *root)
{
   
   //base case
   if(root == NULL || root->next == NULL)
   {
       return root;
   }
   
   root->next = flatten(root->next);
   root = merge(root,root->next);
   return root;

 
}