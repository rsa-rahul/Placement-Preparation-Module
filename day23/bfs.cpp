vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
    vector<int> bfs_traversal;
    vector<bool> vis(V, false);
    queue<int> q;
    vis[0] = true;
     q.push(0);
        while (!q.empty()) {
          int g_node = q.front();
            q.pop();
             bfs_traversal.push_back(g_node);
              for (auto it : adj[g_node]) {
                 if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                 }
              }
        }
        
    return bfs_traversal;
    }