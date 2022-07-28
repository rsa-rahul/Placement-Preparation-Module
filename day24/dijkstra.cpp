vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
   {

       //ans array which is to be returned


       vector<int> distance(V,INT_MAX);
       

       //priority queue to get shortest weighted distance , pair of             //    {wt,node} 
       multiset<pair<int,int>> q;
       int source = S;
       q.insert({0,source});
       distance[source] = 0;
       
       while(!q.empty()){
           auto it = *(q.begin());
           int currnode = it.second;
           int dis = it.first;
           
           q.erase(q.begin());
           
           auto children = adj[currnode];
           
           for(int i=0;i<children.size();i++){
               int v = children[i][0];
               int wet = children[i][1];
               
               if(distance[currnode] + wet < distance[v]){
                   distance[v] = distance[currnode] + wet;
                   q.insert({distance[v],v});
               }
           }
       }
       return distance;
   }s