vector<int> leftView(Node *root)
{
   queue<Node*> q;
   vector<int> res;
    if(!root)return res;
   q.push(root);
   while(!q.empty()){
       int n = q.size();
       bool flag = false;
       while(n--){
           Node* node = q.front(); q.pop();
           if(!flag){
               res.push_back(node->data);
               flag = true;
           }
           if(node->left)q.push(node->left);
           if(node->right)q.push(node->right);
       }
   }
   return res;
}