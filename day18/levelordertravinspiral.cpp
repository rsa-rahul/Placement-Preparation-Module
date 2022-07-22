class Solution {
public:
    void bfs(TreeNode* root, int level, vector<vector<int>> &res){
                if(!root) return;
                if(res.size() == level) res.push_back({});
                res[level].push_back(root->val);
                if(root->left) bfs(root->left, level+1, res);
                if(root->right) bfs(root->right, level+1, res);
        }
    vector<vector<int>>levelOrder(TreeNode* root) {
        vector<vector<int>> res;
            bfs(root, 0, res);
            return res;
    }
};