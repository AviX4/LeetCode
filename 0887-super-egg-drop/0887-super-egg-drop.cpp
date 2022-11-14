class Solution {
    int t[101][10001];
public:
    
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(k,n);
    }

    int solve(int e,int f){
        if(e==1){
            return f;
        }
        if(f==0 || f==1){
            return f;
        }
        if(t[e][f]!=-1){
            return t[e][f];
        }
        
        int mn=INT_MAX;
        int start=0;
        int end=f;
        while(start<=end){
            int middle= (start+end)/2;
            int left=solve(e-1,middle-1);
            int right=solve(e,f-middle);
            int temp=1+max(left,right);
            if(left<right){
                start=middle+1;
            }else{
                end=middle-1;
            }
            mn=min(mn,temp);
        }
        return t[e][f]=mn;
    }
};