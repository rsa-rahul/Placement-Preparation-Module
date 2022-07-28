class Solution {
public:
    void findTopoSort(int source,stack<int>&st,vector<int>&vis,vector<int>adj[]) {
        vis[source] = true;
        for(auto it : adj[source]) {
            if(vis[it] == false) {
                findTopoSort(it,st,vis,adj);
            }
        }
        st.push(source);
    }
	vector<int> topoSort(int V, vector<int> adj[])  {
	    stack<int>st;
	    vector<int>ans;
	    vector<int>vis(V + 1,false);
	    for(int i = 0; i < V; i++) {
	        if(vis[i] == false) {
	            findTopoSort(i,st,vis,adj);
	        }
	    }
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};