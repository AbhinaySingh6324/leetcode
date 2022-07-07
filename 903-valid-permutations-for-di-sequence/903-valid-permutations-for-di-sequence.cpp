class Solution {
public:
    int mod = 1000000007;
     int kill(vector<vector<int>>&dp,vector<bool>&vis, int i , int start, string &s, int n)
     {
       if(i==n-1) return 1;
          
         if(dp[i][start]!=-1) return dp[i][start];
          int ans = 0 ;
          if(s[i]=='D')
          {
               for( int j = 0;j<start;j++)
               {
                    if(!vis[j])
                    {
                    vis[j] = 1;
                     ans += kill(dp,vis,i+1,j,s,n);
                     ans %=mod;
                     vis[j] = 0;
                    }
                    
               }
          }
          else
          {
               for(int  j = start+1;j<n;j++)
               {
                    if(!vis[j])
                    {
                        vis[j] = 1;
                     ans += kill(dp,vis,i+1,j,s,n);
                     ans %=mod;
                     vis[j] = 0;
                    }
               }
          }
          return dp[i][start] = ans;
     }
    
    int numPermsDISequence(string s) {
         int n = s.length();
          vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
          vector<bool>vis(n+1,0);
        
         
         int ans = 0 ;
          for( int i =0 ; i<n+1;i++)
          {       vis[i] = 1;
                  ans += kill(dp,vis,0,i,s,n+1);
                  ans %=mod;
                  vis[i] = 0;
               
          }
         return ans;
        
    }
};