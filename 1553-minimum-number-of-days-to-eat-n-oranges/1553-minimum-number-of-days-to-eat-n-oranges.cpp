class Solution {
public:
    
      
     unordered_map<int,int>dp;
     int solve( int i)
     {   if(i==1) return 1;
         if(i==2) return 2;
             if(dp.count(i)) return dp[i];
      int ans = INT_MAX;
       if(i%2==0)
       {
            ans = min(solve(i/2)+1,ans);
           
       }
       if(i%3==0)
       {
            ans = min(ans,solve(i/3)+1);
       }
       if((i-1)%2==0||(i-1)%3==0)
       {
             ans = min(ans,1+solve(i-1));
       }
      
       if((i-2)%3==0)
       {
            ans =  min(ans,2+solve(i-2));
       }
      
      return dp[i] = ans;
     }
    
    int minDays(int n) {
         
          return solve(n);   
    }
};