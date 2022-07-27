void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
  if(root==NULL) return ;
   
   findPreSuc(root->left,pre,suc,key);
   if(root->key<key)  pre=root;
   else if(suc==NULL and root->key>key) suc = root;
   findPreSuc(root->right,pre,suc,key);
   return ;

}