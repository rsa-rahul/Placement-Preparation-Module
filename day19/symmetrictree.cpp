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
public:
    bool inordert(TreeNode* root, TreeNode* root1)
    {
        int ans = true;

        if(root == NULL && root1 == NULL) return true;
        if(root == NULL || root1 == NULL) return false;
        if(root->val != root1->val) return false;
        
        ans = ans & inordert(root->left, root1->right);
        if(ans == false) return ans;
        
        ans = ans & inordert(root->right, root1->left);
        
        return ans;
    }
    bool isSymmetric(TreeNode* root) 
    {
        return inordert(root, root);
    }
};