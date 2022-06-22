class Solution {
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string>> res;
         vector<string> ans;
         func(0,s,res,ans);
         return res;
        
    }
    
     void func(int ind,string s, vector<vector<string>> &res, vector<string> &ans)
     {
          if(ind==s.size())
          {
              res.push_back(ans);
              return;
          }
         
          for(int  i = ind; i <s.size(); i++ )
          {
              if (ispal(s, ind, i))
              {
                  ans.push_back(s.substr(ind,i-ind+1));
                  func( i+1,s,res,ans);
                  ans.pop_back();
              }
          }
     }
    
     bool ispal(string s,int start, int end)
    {
    while(start <=end){
        if(s[start++]!=s[end--])
            return false;
    }
    return true;
}
    
};