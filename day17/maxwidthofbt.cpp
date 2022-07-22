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
    int widthOfBinaryTree(TreeNode* root) {
        deque <pair<TreeNode * ,long long>> dq; // <Node ,index>
        long global_max=1, level_max=1;
        if(root==NULL)
            return 0;
        else
        {
            dq.push_back({root,1});
            while(!dq.empty())
            {
                int count = dq.size();
                level_max = dq.back().second -dq.front().second +1;
                global_max= max(level_max,global_max);
                int min_index=dq.front().second; 
                for(int i=count;i>0;i--)
                {
                    auto temp= dq.front();
                    dq.pop_front();
                    if(temp.first->left)
                        dq.push_back({temp.first->left , (((temp.second-min_index)-1)*2) +1 });
                    if( temp.first->right)
                        dq.push_back({temp.first->right , (((temp.second-min_index)-1)*2) +2});
                        
                    
                }
                
            }
        }
        
        return global_max;
    }
};