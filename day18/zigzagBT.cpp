class Solution
{
public:
    using node = TreeNode;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        ios_base::sync_with_stdio(0);
        if (!root)
            return {};
        queue<node *> q;
        bool level = 0;
        vector<vector<int>> res;
        vector<int> temp;
        q.push(root);
        while (!q.empty())
        {
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                node *curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (!level)
            {
                res.push_back(temp);
                level = 1;
            }
            else
            {
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                level = 0;
            }
            temp.clear();
        }
        return res;
    }
};