class Solution {
public:
    int find(int m,int n,vector<vector<char>>& grid) {
        bool outbounds = m<0 || n<0 || m==grid.size() || n==grid[0].size();
        if(outbounds )
            return 0;
        if(grid[m][n]=='0' || grid[m][n]=='*')
            return 0;
        grid[m][n] = '*';
        find(m+1,n,grid);
        find(m-1,n,grid);
        find(m,n+1,grid);
        find(m,n-1,grid);
        
        return 1;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                count+=find(i,j,grid);
            }
        }
        return count;
    }
};