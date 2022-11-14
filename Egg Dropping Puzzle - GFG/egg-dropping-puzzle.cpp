//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int t[201][201];
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
    int solve(int e,int f){
        if(e==1){
            return f;
        }if(f==1 || f==0){
            return f;
        }
        if(t[e][f]!=-1){
            return t[e][f];
        }
        int mn=INT_MAX;
        for(int k=1;k<=f;k++){
            int temp=1+max(solve(e-1,k-1),solve(e,f-k));
            mn=min(mn,temp);
        }
        return t[e][f]=mn;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends