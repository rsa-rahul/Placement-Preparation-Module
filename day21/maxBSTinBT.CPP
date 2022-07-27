/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */class Solution {
public:
    //data structure <sum,<min,max>>
    pair<int,pair<int,int>> solve(TreeNode* root,int &ans)
    {   if(!root){return {0,{INT_MAX,INT_MIN}}; }
        
        auto left=solve(root->left,ans);  //process left
        auto right=solve(root->right,ans);  //process right
        if(left.first==INT_MIN || right.first==INT_MIN)
        {return {INT_MIN,{INT_MIN,INT_MAX}}; } //if any subtree is not bst return back
     
     
        if(root->val > left.second.second and root->val < right.second.first)     
            //curr node satisfies bst
        {   
            ans=max(ans,left.first+right.first+root->val);   //max till now
        
            return 
            { left.first+right.first+root->val,    //sum
             {min(left.second.first,root->val),     //min
              max(right.second.second,root->val)}   //max
            };         
        }
        
        return {INT_MIN,{INT_MIN,INT_MAX}};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return max(0,ans);
    }
};