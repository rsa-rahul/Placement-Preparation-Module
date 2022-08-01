 int matrixMultiplication(int N,int mat[])

{

   vector<vector<int>>dp(N,vector<int>(N,0)); 

       for(int i=N-1;i>=1;i--)

       {

           for(int j=i+1;j<=N-1;j++)

           {

               int ans=INT_MAX; 

               for(int k=i;k<j;k++)

               {

                   dp[i][j]=mat[i-1]*mat[k]*mat[j]+

                   dp[i][k]+dp[k+1][j]; 

                   ans=min(ans,dp[i][j]); 

               }

               dp[i][j]=ans; 

           }

       }

       return dp[1][N-1];

    }