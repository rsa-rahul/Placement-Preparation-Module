class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int>dp(nums.size(),0);  //vector same as size of nums
        int ans=nums[0];                     //for the edge case nums.size()=1
        dp[0]=nums[0];                       //initialising dp
        
        for( int i=1;i<nums.size();i++)      
        {
                         
            dp[i]=max(dp[i-1]+nums[i],nums[i]);             // it will cover all cases negative or positive
            ans=max(dp[i],ans);                                      //ans will be max of the elements in dp
        }
      return ans;
        
    }
};