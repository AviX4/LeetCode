class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=0;
        for(int i=0;i<piles.size();i++){
            r=max(piles[i],r);
        }
        int ret=r;
        while(l<=r){
            int k=(l+r)/2;
            long long int res=0;
            for(int i=0;i<piles.size();i++){
                res+=ceil((double)piles[i]/k);
            }
            if(res<=h){
                ret=min(k,ret);
                r=k-1;
            }else if(res>h){
                l=k+1;
            }
        }
        return ret;
    }
};