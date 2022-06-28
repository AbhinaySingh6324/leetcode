class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(), pairs.end(), cmp);
         vector<int>&pair = pairs[0];
          int cnt = 1;
         for( int i = 1; i<pairs.size() ;i++)
         {
             if(pairs[i][0]>pair[1])
             {
                 cnt++;
                 pair = pairs[i];
             }
         }
        
        return cnt;
    }
    
private:
    static bool cmp( vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1] || a[1]==b[1] and a[0]<b[0] ;
    }
};