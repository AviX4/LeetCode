class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<abs(target) || (sum+target)%2!=0){
            return 0;
        }
        int s=(target+sum)/2;
        return solve(nums,s);
    }
private:
    int solve(vector<int>& a,int target){
        int n=a.size(),w=target;
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};