class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]+i>=r){
                r=i;
            }
        }
        if(r==0){
            return true;
        }
        return false;
    }
};