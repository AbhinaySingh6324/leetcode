class Solution {
public:
     int kill(int x , vector<vector<int>>&s)
     {  int n = s.size();
        for(int i =0 ;i<n;i++)
        {   if((1<<i)&x){
                for(int j  = 0; j<n;j++)
                {
                    if(s[i][j]==0 and ((1<<j)&x) or s[i][j]==1 and !((1<<j)&x))  return false;
                }}
            
        }
         return true;
     }
    
    
    int maximumGood(vector<vector<int>>&a) {
         int ans = 0;
        int n = a.size();
        int m = 1<<n;
        for(int i = 0;i<m;i++){
            if(kill(i,a)) ans = max(ans, __builtin_popcount(i));
        }
        return ans;
        
    }
};