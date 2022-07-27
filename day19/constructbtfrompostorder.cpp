class Solution {
public:
	TreeNode* makeTree(vector<int>& post, int pS, int pE, vector<int>& in, int iS, int iE, unordered_map<int,int>& mp)
	{
		if(iS>iE || pS>pE)  return NULL;
		TreeNode *root = new TreeNode(post[pE]);
		int inRoot = mp[root->val];
		int left = inRoot-iS;
		root->left = makeTree(post,pS,pS+left-1,in,iS,inRoot-1,mp);
		root->right = makeTree(post,pS+left,pE-1,in,inRoot+1,iE,mp);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int,int> mp;
		for(int i=0;i<inorder.size();i++)   mp[inorder[i]] = i;
		return makeTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
	}
};