class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int f=dfs(nums,0,nums.size()-2);
        int s=dfs(nums,1,nums.size()-1);
        return max(f,s);
    }
    
    int dfs(vector<int>& nums,int start,int end){
        int prev=0;
        int curr=0;
        int next=0;
        for(int i=start;i<=end;i++){
            next=max(prev+nums[i],curr);
            prev=curr;
            curr=next;
        }
        return curr;
    }
};