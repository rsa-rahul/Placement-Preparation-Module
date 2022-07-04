class Solution {
public:
    int maxProfit(vector<int>& prices){
        int mn=INT_MAX;
        int best=0;
        for(int i=0;i<prices.size();i++){
            mn=min(mn,prices[i]);
            best=max(best,prices[i]-mn);
        }
        return best;
    }
};