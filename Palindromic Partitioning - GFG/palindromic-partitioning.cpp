//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[501][501];
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        int res = solve(str,0,str.length()-1);
        return res;
    }
    bool check(string s,int i,int j){
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string s,int i,int j){
        if(i>=j){
            return 0;
        }
        if(check(s,i,j)== true){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            int l,r;
            if(t[i][k]!=-1){
                l=t[i][k];
            }else{
                l=solve(s,i,k);
                t[i][k]=l;
            }if(t[k+1][j]!=-1){
                r=t[k+1][j];
            }else{
                r=solve(s,k+1,j);
                t[k+1][j]=r;
            }
            int temp=1+l+r;
            ans=min(temp,ans);
        }
        return t[i][j]=ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends