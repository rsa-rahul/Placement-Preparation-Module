class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        unordered_map<int,int> mp;
        vector<vector<int>> ans;
        sort(A.begin(),A.end());
        int n=A.size();
        for(int i=0;i<n;i++) mp[A[i]]=i;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find((A[i]+A[j])*(-1))!=mp.end()){
                    if(mp[(A[i]+A[j])*(-1)]>j){
                        vector<int> p;
                        p.push_back(A[i]);
                        p.push_back(A[j]);
                        p.push_back((A[i]+A[j])*(-1));
                        ans.push_back(p);
                    }
                }
                j=mp[A[j]];
            }
            i=mp[A[i]];
        }
        return ans;
    }
};
