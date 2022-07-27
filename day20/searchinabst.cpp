class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current= root;
        while(current!=NULL){
            if(current->val==val){
                return current;
            }
            if(val>current->val){
                current= current->right;
            }else{
                current= current->left;
            }
        }
        return NULL;
    }
};