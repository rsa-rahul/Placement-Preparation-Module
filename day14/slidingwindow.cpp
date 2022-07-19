class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
        int n = nums.size();
        vector<int> sol;
        
        unordered_map<int, int>m;
        priority_queue<int>pq;
        
        if(k==1) return nums;
        
        if(k == n){
           for(int i=0; i<n; i++){
            pq.push(nums[i]);
                 } 
            sol.push_back(pq.top());
            return sol;
        }
        
        
        for(int i=0; i<k; i++){
            
            pq.push(nums[i]);
            m[nums[i]]++;
        }
        
        sol.push_back(pq.top());
        
        for(int i=k; i<n; i++){
            m[nums[i-k]]--;
            int last_max = pq.top();
            
            while(m[last_max] ==0){
                pq.pop();
                last_max = pq.top();
            }
            
            m[nums[i]]++;
            pq.push(nums[i]);
            
            sol.push_back(pq.top());
        }
        
        return sol;
        
        
    }
};