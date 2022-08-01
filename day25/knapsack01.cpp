class Solution {
public:

int findMaxForm(vector<string>& strs, int m, int n) {
    int n1=strs.size();
    
    vector<int> ones(n1,0);
    vector<int> zero(n1,0);
    
    for(int i=0;i<n1;i++)
    {
        string s=strs[i];
        int n2=s.length();
        for(int j=0;j<n2;j++)
            if(s[j]=='0')
                zero[i]++;
        
        ones[i]=n2-zero[i];
    }
    
    int res=0;
    
    int dp[m+1][n+1][n1+1];
    
    for(int k=0;k<=n1;k++)
    {for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0  &&  j==0)
            {dp[i][j][k]=0;
            continue;
            }
            
            if(k==0)
            {
                dp[i][j][k]=0;
                continue;
            }
            
           if(zero[k-1]<=i  &&  ones[k-1]<=j)
           {
               dp[i][j][k]=max(dp[i][j][k-1],1+dp[i-zero[k-1]][j-ones[k-1]][k-1]);
           }
            else dp[i][j][k]=dp[i][j][k-1];
            
            
        }
    }}
    
    return dp[m][n][n1];
    
}

};