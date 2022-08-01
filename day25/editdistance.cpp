class Solution {
public:
 int minDistance(string word1, string word2) {
        int n1 = word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i=0;i<n1;i++) dp[i][n2] = n1-i;
        for(int j=0;j<n2;j++) dp[n1][j] = n2-j;
        for(int i=n1-1;i>=0;i--)
            for(int j=n2-1;j>=0;j--) 
                dp[i][j] = word1[i]==word2[j]? dp[i+1][j+1] : min(min(dp[i][j+1],dp[i+1][j]),dp[i+1][j+1])+1;
        return dp[0][0];
    }
};