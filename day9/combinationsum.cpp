class Solution {
public:
    void f(vector<int>& candidates,int i,int target,vector<vector<int>>& ans,vector<int>& curr)
    {
        if(i==candidates.size()){
            if(target==0)
                ans.push_back(curr);
            return;
        }

        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            f(candidates,i,target-candidates[i],ans,curr);
            curr.pop_back();
        }
        f(candidates,i+1,target,ans,curr);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int i=0;
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        f(candidates,i,target,ans,curr);
        return ans;
    }
};