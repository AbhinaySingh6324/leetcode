#define ll long long
class Solution {
public:
     ll min(ll a,ll b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    
    int dp[101][101][31];
     int kill(vector<int>& houses, vector<vector<int>>& cost, ll m, ll n, ll target, ll index, ll last)
     {
          if(target<0) return INT_MAX;
          if(index==m)
          {
               if(target==0) return 0;
               else return INT_MAX;
              
          }
          
           if(dp[target][index][last]!=-1)
           {
                return dp[target][index][last];
           }
          // if coloured 
          if(houses[index]!=0 and last==houses[index])
          {
             return dp[target][index][last] =  kill(houses,cost,m,n,target,index+1,houses[index]);
              
              
                 
          }
        else  if(houses[index]!=0)
          {
            return  dp[target][index][last] =  kill(houses,cost,m,n,target-1,index+1,houses[index]);
         }
         
          ll ans = INT_MAX;
           for(int i  = 0 ;i < n ;i++)
           {
                if(i+1!=last) ans = min(ans, 1LL*kill(houses,cost,m,n,target-1,index+1,i+1)+cost[index][i]);
               else ans = min(ans, 1LL*kill(houses,cost,m,n,target,index+1,i+1)+cost[index][i]);
                                           
                                       
           
     
               }
          return dp[target][index][last] = ans;
     }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        memset(dp,-1,sizeof(dp));
        ll index=0;
        ll last_color=0;
        ll ans= kill(houses,cost,m,n,1LL*target,index,last_color);
        return (ans==INT_MAX)? -1 : (int)ans;
    }
};