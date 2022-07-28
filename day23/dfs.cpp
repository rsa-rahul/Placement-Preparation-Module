class Solution {
   
   void dfs(int i, vector<int>* adj, vector<int>& ans, vector<bool>& vis){
       ans.push_back(i);
       vis[i] = true;
       
       for(auto it: adj[i]){
           if(!vis[it]){
               dfs(it, adj, ans, vis);
           }
       }
   }
   
 public:
   // Function to return a list containing the DFS traversal of the graph.
   vector<int> dfsOfGraph(int n, vector<int> adj[]) {
       vector<int> ans;
       vector<bool> vis(n, false);
       dfs(0, adj, ans, vis);
       return ans;
   }
};