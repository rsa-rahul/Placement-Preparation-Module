int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int presum=0,res=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            presum+=A[i];
            if(presum==0) res=i+1;
            if(mp.find(presum)!=mp.end()) res=max(res,i-mp[presum]);
            mp.insert({presum,i});
        }
        return res;
    }