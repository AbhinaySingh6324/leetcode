// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
         int foo = 0;
         int ans = 0;
        if(N<=M || (S>6 and N*6<=M*7)) return -1;
         else
         {
             int cnt =1;
             while(1)
             {
                 if(N*cnt-M*S<0)
                 {
                     cnt++;
                 }
                 else break;
             }
             return cnt;
         }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends