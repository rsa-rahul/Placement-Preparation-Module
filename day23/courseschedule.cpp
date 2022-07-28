class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create an adjacency list
        vector<vector<int>> AList(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(vector<int>& edge : prerequisites){
            int u = edge[1];
            int v = edge[0];
            
            AList[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> queue;
        
        // add all the vertices with indegree 0 to the queue
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                queue.push(i);
            }
        }
        
        // perform topological sorting
        while(not queue.empty()){
            int u = queue.front();
            queue.pop();
            
            for(int v : AList[u]){
                indegree[v]--;
                
                if(indegree[v] == 0){
                    queue.push(v);
                }
            }
        }
        
        // if indegree of all nodes is 0, then we can finish all the courses, else we can't
        for(int i=0; i<numCourses; i++){
            if(indegree[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};