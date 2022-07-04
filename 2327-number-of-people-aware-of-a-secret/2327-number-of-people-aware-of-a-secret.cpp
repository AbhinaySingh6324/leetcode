class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
           vector<long long>dp(n+1,0); //zero based indexing
          int mod   = 1000000007;
          dp[0] = 1; // intially known to 1 person
         for( int i =1 ;i <n ;i++)
         {
        if((i-delay)<0) dp[i] = dp[i-1];// just the number people who knew yesterday still know it today.
             
        else if((i-delay)>=0 and (i-forget)<0)
        {
    dp[i] = (dp[i-1]+dp[i-delay]+mod)%(mod);//the people who completed their delay  will now tell it to someone along with people who know it from yesterday.
        }
       else
         {
              dp[i] =(dp[i-1]+dp[i-delay]-dp[i-forget]+mod)%(mod);//the people who completed their delay  will now tell it to someone  but the forgotten ones will not contribute to the distribution along with people who know it from yesterday.
           } 
         }
         int lastF = n-1-forget; //people who knew the secret up until this day will forget it on the nth day
		if(lastF>=0)
        {
             return  (dp[n-1] - dp[lastF] + mod)%mod;
        }
        return  dp[n-1]%mod;// we have been asked to get the answer at the end of the  nth day so the people 
        
    }
};