class Solution {
public:
    int solve(vector<int>nums,int start,int end)
    {
        if(start>end)
            return -1;
        
        int mid=start+(end-start)/2;
        
        if(mid>0 && nums[mid]==nums[mid-1])
        {
            if((mid-1)%2!=0)
                return solve(nums,start,mid-2);
            else
                return solve(nums,mid+1,end);
        }
        else if(mid<nums.size()-1 && nums[mid]==nums[mid+1])
        {
            if(mid%2!=0)
                return solve(nums,start,mid-1);
            return solve(nums,mid+2,end);
        }
        else
            return nums[mid];
    }
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};
