vector<int> topKFrequent(vector<int>& nums, int k) {
        //map for keeping track of freq of each element
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        //create min heap with pair
        //pair<int,int>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mh;
		//traversing in map and pushing each freq & element.
        for(auto x:mp){
            mh.push({x.second,x.first});
            if(mh.size()>k){
                mh.pop();
            }
        }
        vector<int>ans;
        while(!mh.empty()){
            ans.push_back(mh.top().second);
            mh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }