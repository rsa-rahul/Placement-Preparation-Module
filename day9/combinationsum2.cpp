class Solution {
public:
    void generate(int idx,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans)
    {
       
        int n=arr.size();
            if(target==0)
            {
                ans.push_back(ds);
                
            }
        
        for(int i=idx;i<n;i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
              if(arr[i]>target) break;
             ds.push_back(arr[i]);
            generate(i+1,target-arr[i],arr,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
         sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        generate(0,target,arr,ds,ans);
        return ans;
        }
};