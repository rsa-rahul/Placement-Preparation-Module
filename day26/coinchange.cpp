class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>curr(amount+1,1e8);
        curr[0]=0;
        for(int idx=1;idx<=n;idx++){
            for(int target=1;target<=amount;target++){
                int pick=1e8;
                int notpick= 0 + curr[target];
                if(target>=coins[idx-1]){
                    pick=1+curr[target-coins[idx-1]];
                }
                 curr[target]=min(pick,notpick);
            }
            
        }
        int count= curr[amount];
        return (count>=1e8?-1:count);
    }
};