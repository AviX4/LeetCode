class Solution {
public:
    unordered_map <string,int> mp;
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.length()==0 && s2.length()==0){
            return true;
        }
        return solve(s1,s2);
    }

private:
    bool solve(string a,string b){
        if(a.size() != b.size()) return false;
        int n = a.size();
        if(a==b || n==0) return true;
        
        string key=a+' '+b;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
       
        bool flag=false;
        for(int i=1;i<=n-1;i++){
            if(solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true){
                flag|=true;
                break;
            }
            
            if(solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true){
                flag|=true;
                break;
            }
        }
        return mp[key]=flag;
    }
};