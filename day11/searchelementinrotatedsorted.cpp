class Solution {
public:
     int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(target==nums[left]){
                return left;
            }
            left++;
            if(target==nums[right]){
                return right;
            }
            right--;
        }
        return -1;
    }
};