class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(0,nums,curr,res);
        return res;
    }
private:
    void solve(int index,vector<int>& nums,vector<int> curr,vector<vector<int>>& res){
        if(index==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(index+1,nums,curr,res);
        curr.pop_back();
        int i=index+1;
        while(i<nums.size() && nums[i-1]==nums[i]){
            i++;
        }
        solve(i,nums,curr,res);
    }
};