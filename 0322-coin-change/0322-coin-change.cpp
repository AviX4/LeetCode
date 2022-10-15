class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int w=amount;
        int t[n+1][w+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                
                if(i==0){
                    t[i][j]=INT_MAX-1;
                }
                if(j==0){
                    t[i][j]=0;
                }
            }
        }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][w]==INT_MAX-1){
            return -1;
        }
        return t[n][w];
    }
};