int wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict(B.begin(),B.end());
    int n = A.size();
    bool dp[n+1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        string cur;
        for(int j = i; j < n; j++){
            cur.push_back(A[j]);
            if(dict.count(cur) && dp[i])
                dp[j+1] = 1;
        }
    }
    return dp[n];
}