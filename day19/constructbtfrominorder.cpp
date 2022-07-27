class Solution {
public:
    TreeNode*helper(int preS, int preE, int inS,int inE,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp)
    {
      if(preS>preE) return NULL;
        
        TreeNode*root=new TreeNode(preorder[preS]);
        if(preS==preE) return root;
        
        int rootindex=mp[preorder[preS]];
        int lpreS=preS+1;
        int rpreE=preE;
        int linS=inS;
        int linE=rootindex-1;
        int rinS=rootindex+1;
        int rinE=inE;
        int lpreE=linE-linS+lpreS;
        int rpreS=lpreE+1;
        
        TreeNode*L=helper(lpreS,lpreE,linS,linE,preorder,inorder,mp);
        TreeNode*R=helper(rpreS,rpreE,rinS,rinE,preorder,inorder,mp);
        
        root->left=L; root->right=R;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
          mp[inorder[i]]=i;  
        }
        return helper(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder,mp);
    }
};