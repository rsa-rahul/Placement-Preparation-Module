void dfs(Node *root,map<int,int> &mp,int dp,int dpth,map<int,int> &ldp)
    {
        if(root)
        {
            if(dpth>=ldp[dp])
             {
                 mp[dp]=root->data;
                 ldp[dp]=dpth;
             }
             dfs(root->left,mp,dp-1,dpth+1,ldp);
             dfs(root->right,mp,dp+1,dpth+1,ldp);
        }
    }
    vector <int> bottomView(Node *root) 
    {
       vector<int> ans;
       map<int,int> mp;
       map<int,int> ldp;
       dfs(root,mp,0,0,ldp);
       
       for(auto t:mp)
         ans.push_back(t.second);
         
         return ans;
    }