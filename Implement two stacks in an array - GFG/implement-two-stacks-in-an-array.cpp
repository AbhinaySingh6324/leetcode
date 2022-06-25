// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};



int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends


  
    // Method to push an element x to stack1
    void twoStacks::push1(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1+1 < top2) {
            top1++;
            arr[top1] = x;
        }
        else
        {
            return;
        }
     
    }
  
    // Method to push an element
    // x to stack2
    void twoStacks::push2(int x)
    {
  
        // There is at least one empty
        // space for new element
        if (top2-1>top1) {
            top2--;
            arr[top2] = x;
        }
        
    }
  
    // Method to pop an element from first stack
    int twoStacks::pop1()
    {
        if (top1!=-1) {
            int x = arr[top1];
            top1--;
            return x;
        }
       else return -1;
    }
  
    // Method to pop an element
    // from second stack
    int twoStacks::pop2()
    {
        if (top2!=size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else return -1;
       
    }

