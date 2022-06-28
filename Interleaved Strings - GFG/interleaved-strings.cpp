// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
     bool kill(  string a , string b, string c  , int  n, int  m , int o )
     {if(o==0) return true;
      if(dp[n][m]!=-1) return dp[n][m];
        int i = 0, j = 0;
         if(n-1>=0 and a[n-1]==c[o-1]) i = kill(a,b,c,n-1,m,o-1);
         if(m-1>=0 and b[m-1]==c[o-1]) j = kill(a,b,c,n,m-1,o-1);
        
         return dp[n][m] = i|j;
         
     }/*You are required to complete this method */
    
    
    bool isInterleave(string a, string b, string c) 
    {  int n = a.size();
        int m = b.size();
        int o = c.size();
        if(n+m != o)return false;
        memset(dp,-1,sizeof(dp));
        return kill(a,b,c,n,m,o);
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends