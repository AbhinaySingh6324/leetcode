// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long   dp[1001][1001];
      long long opt( int arr[], int i, int j)
    { if(i>j)return 0;
      if (dp[i][j]!=-1) return dp[i][j];
           int  a = arr[i]+min(opt(arr,i+2,j),opt(arr,i+1,j-1));
           int b = arr[j] +min(opt(arr,i,j-2), opt(arr,i+1,j-1));
           
           dp[i][j] = max(a,b);
            return dp[i][j]; 
       
        
    }
    
    long long maximumAmount(int arr[], int n){
          dp[n][n];
           memset(dp,-1,sizeof(dp));
            return opt(arr,0,n-1);
        
        // Your code here
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends