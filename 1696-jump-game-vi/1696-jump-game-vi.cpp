class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
         priority_queue<pair<int,int>>pq;
         int n =  nums.size();
         vector<int>dp(n,0);
         dp[0] = nums[0];
         pq.push({dp[0],0});
         for(int i  = 1 ; i<n;i++)
         {
              while(pq.top().second<i-k)
              {
                  pq.pop();
              }
             dp[i] = pq.top().first+nums[i];
             pq.push({dp[i],i});
         }
         return dp[n-1];
        
    }
};