class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    int dp[r][c];
    for(int i=r-1;i>=0;i--){
        for(int j=c-1 ; j>=0 ; j--){
            if(i==r-1 and j==c-1){ 
                dp[i][j]=grid[i][j];
            }
            else if(i==r-1){
                dp[i][j]=grid[i][j]+dp[i][j+1];
            }
            else if(j==c-1){ 
                dp[i][j]=grid[i][j]+dp[i+1][j];
            }
            else{ 
                dp[i][j] = grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
            
        }
    }
    return dp[0][0];
}
};