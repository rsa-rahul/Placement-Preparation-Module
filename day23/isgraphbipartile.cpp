class Solution {
public:

	/* BFS Solution */
	bool bipartiteBFS(int i, vector<vector<int>> adj, vector<int>& visited){

		queue<int> q;
		q.push(i);
		visited[i] = 1;

		while(!q.empty()){

			int node = q.front();
			q.pop();

			for(auto it : adj[node]){
				if(visited[it] == -1){
					visited[it] = 1 - visited[node];
					q.push(it);
				}
				else if(visited[it] == visited[node]){
					return false;
				}
			}
		}

		return true;
	}


	/* DFS Solution */    
	bool bipartiteDFS(int node,vector<vector<int>>vec,vector<int> &vis){
		if(vis[node] == -1){
			vis[node] = 1;
		}


		for(auto it:vec[node]){
			if(vis[it] == -1){
				vis[it] = 1- vis[node];
				if(bipartiteDFS(it,vec,vis) == false){
					return false;
				}
			}else if(vis[node] == vis[it]){
				return false;
			}
		}
		return true;
	}  


	bool isBipartite(vector<vector<int>>& adj) {

		vector<int> visited(adj.size(), -1);

		for(int i=0 ; i<adj.size() ; i++){
			if(visited[i] == -1){ // Not visited
				if(!bipartiteDFS(i, adj, visited)){
					return false;
				}
			}
		}

		return true;
	}
};