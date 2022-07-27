class Solution
{
    public: int i=0;
   int kthLargest(Node *root, int k)
   {
       //Your code here
       if(!root) return -1;
       //right
       int r=kthLargest(root->right,k);
       if(r!=-1) return r;
       
       //node
       i++;
       if(i==k) return root->data;
       //left
       return kthLargest(root->left,k);
   }
};