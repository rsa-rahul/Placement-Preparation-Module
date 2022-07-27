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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
       
        return TreeCreator(nums, 0, n-1);
        
    }
    TreeNode* TreeCreator(vector<int>& nums ,int low, int n){
        if(low>n){
            return NULL;
        }
        int mid = (n+low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = TreeCreator(nums, low, mid-1);
        root->right = TreeCreator(nums, mid+1, n);
        return root;
    }
};