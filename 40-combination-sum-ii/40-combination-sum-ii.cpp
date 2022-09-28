class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates,target,res,temp,0,0);
        return res;
    }
private:
    void solve(vector<int> candidates,int target,vector<vector<int>>& res,vector<int>& temp,int sum,int index){
        if(sum>target){
            return;
        }
        if(sum==target){
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target,res,temp,sum+candidates[i],i+1);
            temp.pop_back();
        }
    }
};