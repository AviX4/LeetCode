class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> op;
        solve(op,nums,res);
        return res;
    }
private:
    void solve(vector<int> op,vector<int> nums,vector<vector<int>>& res){
        if(nums.size()==0){
            res.push_back(op);
            return;
        }
        vector<int> op1=op;
        vector<int>op2=op;
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        solve(op1,nums,res);
        solve(op2,nums,res);
        return;
    }
};