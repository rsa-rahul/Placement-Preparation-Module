int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,1e9);
        vector<int> mst(V,0);
        //vector<int> par(V,-1);
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0}); //{cost,index};
        int ans=0;
        while(!q.empty())
        {
            int index=q.top().second;
            q.pop();
            mst[index]=1;
            for(auto x:adj[index])
            {
                int v=x[0];
                int cost=x[1];
                if(mst[v]==0 and cost<key[v])
                {
                    key[v]=cost;
                    //par[v]=index;
                    q.push({cost,v});
                }
            }
        }
        for(int i=1;i<V;i++)
        {
            ans+=key[i];
        }
        return ans;
    }