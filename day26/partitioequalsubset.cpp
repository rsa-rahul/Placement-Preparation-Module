class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            int n=arr.size();
            int w=sum/2;
            bool dp[n+1][w+1];
            for(int i=0;i<n+1;i++){
                for(int j=0;j<w+1;j++){
                    if(i==0){
                        dp[i][j]=false;
                    }
                    if(j==0){
                        dp[i][j]=true;
                    }
                }
            }
            for(int i=1;i<n+1;i++){
                for(int j=1;j<w+1;j++){
                    if(arr[i-1]<=j){
                        dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j] ;
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][w];
        }
    }
};