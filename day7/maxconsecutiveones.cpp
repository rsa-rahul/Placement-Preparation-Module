#include<bits/stdc++.h>
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {  
        int n = nums.size(), ans = 0, ct = 0;
        for(int i=0; i<n; i++) {
        (nums[i] == 1) ? ct++ : ct=0;
        ans = max(ans, ct);
        }
return ans;
    }
};