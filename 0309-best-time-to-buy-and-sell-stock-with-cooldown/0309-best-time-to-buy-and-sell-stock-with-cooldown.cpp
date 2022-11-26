class Solution {
    
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        //boolean to keep track of Buy/Sell
        // if buy i++
        // if sell i+=2
        memset(dp,-1,sizeof(dp));
        return dfs(prices,0,1);
        
    }
private:
    int dfs(vector<int>& prices, int i,bool buy){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        
        if(buy){
            int buying = dfs(prices,i+1,!buy) - prices[i];
            int cooldown = dfs(prices,i+1,buy);
            dp[i][buy]=max(buying,cooldown);
        }else{
            int selling = dfs(prices,i+2,!buy)+prices[i];
            int cooldown = dfs(prices,i+1,buy);
            dp[i][buy]=max(selling,cooldown);
        }
        return dp[i][buy];
    }
};