class Solution {
public:
    map <pair<int,int>,int> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                res=max(solve(matrix,i,j,-1),res);
            }
        }
        return res;
    }
    
    int solve(vector<vector<int>>& matrix,int i,int j,int pre){
        if(i>=matrix.size()||i<0||j<0||j>=matrix[0].size()||matrix[i][j]<=pre ){
            return 0;
        }
        if(dp.find({i,j})!=dp.end()){
            return dp[{i,j}];
        }
        int result=1;
        result = max(result,1+solve(matrix,i-1,j,matrix[i][j]));
        result = max(result,1+solve(matrix,i,j-1,matrix[i][j]));
        result = max(result,1+solve(matrix,i+1,j,matrix[i][j]));
        result = max(result,1+solve(matrix,i,j+1,matrix[i][j]));
        
        return dp[{i,j}]=result;
    }
};