//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[201][201][2];
    int mod=1003;
    int countWays(int N, string S){
        // code here
        memset(t,-1,sizeof(t));
        int res=solve(S,0,N-1,1);
        return res;
    }
    
    int solve(string s,int i,int j,bool isTrue){
        if(i>j){
            return false;
        }if(i==j){
            if(isTrue==true){
                return s[i]=='T';
            }else{
                return s[i]=='F';
            }
        }
        if(t[i][j][isTrue]!=-1){
            return t[i][j][isTrue];
        }
        int ans=0;
        for(int k=i+1;k<=j-1;k=k+2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ans=((ans+lt*rt)%mod)%mod;
                }else{
                    ans=(ans+(lt*rf)%mod+(lf*rt)%mod+(rf*lf)%mod)%mod;
                }
            }else if(s[k]=='|'){
                if(isTrue){
                    ans=(ans+(lt*rf)%mod+(rt*lt)%mod+(rt*lf)%mod)%mod;
                }else{
                    ans=(ans+(lf*rf))%mod;
                }
            }else if(s[k]=='^'){
                if(isTrue){
                    ans=(ans+(lt*rf)%mod+(lf*rt)%mod)%mod;
                }else{
                    ans=(ans+(lt*rt)%mod+(rf*lf)%mod)%mod;
                }
            }
        }
        return t[i][j][isTrue]=ans%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends