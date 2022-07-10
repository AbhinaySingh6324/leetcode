class Solution {
public:
    
    inline bool static check(string& s1,string& s2){
        string a,b;
        for(auto it : s1) if(it!='_') a+=it;
        for(auto it : s2) if(it!='_') b+=it;
        return a==b;
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