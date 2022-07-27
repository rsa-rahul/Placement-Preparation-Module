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
 */
class Solution {
    int ans=-1;
    vector<int>arr;
    void finder(TreeNode* root, int k,int &i)
    {
        if(root==NULL)
        {
            return;
        }
        finder(root->left,k,i);
        i++;
        if(i==k)
        {
            ans=root->val;
        }
        finder(root->right,k,i);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int i=0;
        finder(root,k,i);
        return ans;
    }
};