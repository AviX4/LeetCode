class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(int i=0;i<columnTitle.length();i++){
            int c=columnTitle[i]-'A'+1;
            res*=26;
            res+=c;
        }
        return res;
    }
};