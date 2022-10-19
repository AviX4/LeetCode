class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int res=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            int j= arr[i];
            arr[i]=res;
            res=max(j,res);
        }
        return arr;
    }
};