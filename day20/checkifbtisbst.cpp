class Solution {
public:
    bool isBst(TreeNode* root, long min, long max){
        if(!root)
            return true;
        if(root->val <= min || root->val >= max){
            return false;
        }else
            return isBst(root->left, min, root->val) && isBst(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isBst(root, LONG_MIN, LONG_MAX);
    }
};