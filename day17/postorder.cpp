class Solution {
	vector<int> res;

	void postorder(TreeNode* root)
	{
		if(!root)
			return;

		postorder(root->left);

		postorder(root->right);

		res.push_back(root->val);
	}   

public:
	vector<int> postorderTraversal(TreeNode* root) {
		postorder(root);
		return res;
	}
};