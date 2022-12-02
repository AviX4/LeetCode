class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> res={0,nums[0]};
        for(int i=1;i<nums.size();i++){
            res.push_back(max(nums[i]+res[i-1],res[i]));
        }
        return res[res.size()-1];
    }
};