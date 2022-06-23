// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>>mat){
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        int maxi = INT_MIN;
         for( int i =0; i<n ;i++)
         {
             for( int j =0 ; j <m ;j++)
             {
                 if(mat[i][j]==1)
                 {
                     dp[i][j] =1;
                 }
                 else
                 {
                      dp[i][j]=0;
                 }
                 maxi = max(mat[i][j],maxi);
             }
         }
        
         for( int i =1; i<n ;i++)
         {
             for( int j =1 ; j <m ;j++)
             {  if(mat[i][j])
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+mat[i][j];
                else dp[i][j] = 0;
                maxi = max(maxi,dp[i][j]);
             }
         }
         return maxi;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends