class Solution{
    public:
    void solve(vector<vector<int>> m, vector<string> &ans, string p, int i, int j, int n){
        if(i == (n - 1) && j == (n - 1)){
            ans.push_back(p);
            return;
        }
        m[i][j] = 0;
        if(((i + 1) < n) && (m[i + 1][j] == 1))
            solve(m, ans, p + "D", (i + 1), (j), n);
        if(((j + 1) < n) && (m[i][j + 1] == 1))
            solve(m, ans, p + "R", (i), (j + 1), n);
        if((i > 0) && (m[i - 1][j] == 1))
            solve(m, ans, p + "U", (i - 1), (j), n);
        if((j > 0) && (m[i][j - 1] == 1))
            solve(m, ans, p + "L", (i), (j - 1), n);
        m[i][j] = 1;
            
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector <string> ans;
        if(m[0][0]==0)
           return ans;
        if(m[n-1][n-1]==0)
           return ans;
        solve(m, ans, "", 0, 0, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};