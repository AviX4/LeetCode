class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        solve(op,nums,res,0);
        return res;
    }
private:
    void solve(vector<int> op,vector<int> nums,vector<vector<int>>& res,int i){
        if(i==nums.size()){
            res.push_back(op);
            return;
        }
        vector<int> op1=op;
        vector<int>op2=op;
        op2.push_back(nums[i]);
        solve(op1,nums,res,i+1);
        solve(op2,nums,res,i+1);
        return;
    }
};