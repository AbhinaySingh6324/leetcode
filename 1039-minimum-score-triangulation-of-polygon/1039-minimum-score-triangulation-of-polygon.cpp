class Solution {
public:
     int dp[51][51];
    
     int kill( int  l, int r, vector<int>&ans)
     { if(r-l<2) return 0;
       int res =  INT_MAX;
       
        if(dp[l][r]!=-1)
        {
             return dp[l][r];
        }
       for( int i = l+1; i<r; i++)
       {
            res  =  min(res,kill(l,i,ans)+kill(i,r,ans)+(ans[l]*ans[i]*ans[r]));
           
       }
       return dp[l][r] = res;
         
     }
    
    int minScoreTriangulation(vector<int>& ans) {
         memset(dp,-1,sizeof(dp));
          int n =ans.size();
         return kill(0,n-1,ans);
        
    }
};