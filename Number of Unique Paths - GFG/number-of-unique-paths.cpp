//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        long long int t[a+1][b+1];
        for(int i=0;i<a+1;i++){
            for(int j=0;j<b+1;j++){
                if(i==0 || j==0){
                    t[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<a+1;i++){
            for(int j=1;j<b+1;j++){
                t[i][j]=t[i-1][j]+t[i][j-1];
            }
        }
        return t[a-1][b-1];
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends