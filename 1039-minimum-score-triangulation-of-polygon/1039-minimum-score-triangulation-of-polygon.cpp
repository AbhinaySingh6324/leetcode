class Solution {
public:
     int dp[51][51];
    
     int kill( int  l, int r, vector<int>&ans)
     { if(l>=r) return 0;
       int res =  INT_MAX;
       
        if(dp[l][r]!=-1)
        {
             return dp[l][r];
        }
       for( int i = l; i<r; i++)
       {
            res  =  min(res,kill(l,i,ans)+kill(i+1,r,ans)+(ans[l-1]*ans[i]*ans[r]));
           
       }
       return dp[l][r] = res;
         
     }
    
    int minScoreTriangulation(vector<int>& ans) {
         memset(dp,-1,sizeof(dp));
          int n =ans.size();
         return kill(1,n-1,ans);
        
    }
};