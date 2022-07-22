class Solution {
public:
    int ans=0;
    unordered_map<TreeNode*,int> mp; // stores max path length starting from that node
    int dfs(TreeNode* node){
        if(!node) // nullptr node
            return 0;
        if(!mp.count(node)){
            pair<int,int>p={1+dfs(node->left),1+dfs(node->right)};
            mp[node]=max(p.first,p.second);  // max path
            ans = max(ans,p.first+p.second-2); // -1 since we are counting the current node twice 
            // and another -1 because path length consisting of n nodes is n-1
        }
        return mp[node];
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};