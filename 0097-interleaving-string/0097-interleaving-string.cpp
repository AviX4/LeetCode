class Solution {
    
public:
    map <pair<int,int>,bool> dp;

    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length()){
            return false;
        }
        return solve(0,0,s3,s1,s2);
    }
    
    bool solve(int i,int j,string s3,string s1,string s2){
        if(i+j==s3.length()){
            return true;
        }
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        
        if(i<s1.size() && s1[i]==s3[i+j] && solve(i+1,j,s3,s1,s2)){
            return true;
        }
        if(j<s2.size() && s2[j]==s3[i+j] && solve(i,j+1,s3,s1,s2)){
            return true;
        }
        return dp[{i,j}]=false;
    }
};