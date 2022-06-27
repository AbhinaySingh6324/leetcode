// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
         int o = 0;
          int c = 0;
           int n = s.length();
           int l = 0;
           int maxi = 0;
          for( int  i =0 ; i<n; i++)
          {  
              if(s[i]=='(')
              {
                  o++;
              }
              else
              {
                  c++;
              }
              if(c==o)
              {
                  maxi = max(maxi,2*o);
              }
              else if(c>o)
              {
                  c = 0,o = 0;
              }
          }
           o = 0;
           c = 0;
          for( int  i =n-1 ; i>=0; i--)
          {  
              if(s[i]=='(')
              {
                  o++;
              }
              else
              {
                  c++;
              }
              if(c==o)
              {
                  maxi = max(maxi,2*o);
              }
              else if(c<o)
              {
                  c = 0,o = 0;
              }
          }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends