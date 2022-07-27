/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string ser;
    string dser;
    int i;
    void Serializehelper(TreeNode* root)
    {
        if(root == NULL)
        {
            ser += "N ";
            return;
        }
        ser += to_string(root->val) + " ";
        Serializehelper(root->left);
        Serializehelper(root->right);
    }
    TreeNode* Dserializehelper()
    {
        if(i > dser.size() || dser[i] == 'N')
        {
            i = i+2;
            return NULL;
        }
        string temp;
        while(dser[i] != ' ')
            temp += dser[i++];
        TreeNode* root = new TreeNode(stoi(temp));
        i++;
        root->left = Dserializehelper();
        root->right = Dserializehelper();
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ser = "";
        Serializehelper(root);
        return ser;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        dser = data;
        i = 0;
        return Dserializehelper();
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));