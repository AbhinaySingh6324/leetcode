class Solution {
public:
    
    inline  bool check(string &s , string& t)
    {
         vector<int>dp;
         vector<int>dp1;
         for(int i =0 ;i <s.length();i++)
         {
              if(s[i]=='R') dp.push_back(1);
             if(s[i]=='L') dp.push_back(0);
             if(t[i]=='R') dp1.push_back(1);
             if(t[i]=='L') dp1.push_back(0);
         }
         return dp==dp1;
    }
    bool canChange(string s, string t) {
         vector<int>dp,dp1,dpr,dpr1;
         if(s.length()!=t.length()) return false;
         int n =  s. length();
        if(!check(s,t)) return false;
        
         for(int  i =0;i<n ;i++)
         {
             if(s[i]=='L') dp.push_back(i);
             if(s[i]=='R') dpr.push_back(i);
             if(t[i]=='L') dp1.push_back(i);
             if(t[i]=='R') dpr1.push_back(i);
         }
    if(dp.size()!=dp1.size()||dpr.size()!=dpr1.size()) return false;
         
         for(int i =0 ; i< dp.size();i++)
         {
             if(dp[i]<dp1[i]) return false;
             
         }
         for(int i =0 ; i< dpr.size();i++)
         {
             if(dpr1[i]<dpr[i]) return false;
             
         }
      return true;   
    }
};