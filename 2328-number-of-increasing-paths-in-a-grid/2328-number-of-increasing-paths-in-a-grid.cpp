class Solution {
public:
     int solve(vector<vector<int>>& grid, int i, int j, int m, int n,int parent,vector<vector<int>>&dp)
     {if(i<0||j<0||i>=m||j>=n||grid[i][j]<=parent)
     {
      return 0;   
     }
      if(dp[i][j]!=1) return dp[i][j];
      int ans =  1;
       ans += (solve(grid,i+1,j,m,n,grid[i][j],dp)+solve(grid,i,j+1,m,n,grid[i][j],dp)%1000000007+solve(grid,i-1,j,m,n,grid[i][j],dp)%1000000007+solve(grid,i,j-1,m,n,grid[i][j],dp)%1000000007)%1000000007; 
         
      return dp[i][j] = ans;
     }
    
    
    
    int countPaths(vector<vector<int>>& grid) {
        int m= grid.size();
        int n =  grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1)); 
        for( int i = 0;i<m;i++)
         {
             for( int j = 0;j<n;j++)
             {
                 dp[i][j] = 1;
             }
         }
        int ans = 0;
        for( int i = 0;i<m;i++)
         {
             for( int j = 0;j<n;j++)
             {
                 ans+=solve(grid,i,j,m,n,-1,dp)%1000000007;
                 ans%=1000000007;
             }
         }
        return ans;
         
    }
};