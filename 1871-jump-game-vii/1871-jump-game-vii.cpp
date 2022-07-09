class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
         int n = s.length(); 
        vector<bool>dp(n,0);
        int prev = 0;
        dp[0] = 1;
         for(int i = 1;i < n ;i++)
         {
              if(i>=minJ) prev+=dp[i-minJ];
              if(i>maxJ)  prev-=dp[i-maxJ-1];
             
             dp[i] = (s[i]=='0' and prev>0);
         }
         return dp[n-1];
    }
};