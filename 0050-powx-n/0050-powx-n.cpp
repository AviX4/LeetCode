class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        
        if(n<0){
            return 1/pow(x,abs(n));
        }else{
            return pow(x,abs(n));
        }
        
    }
private:
    double pow(double x,int n){
        if(n==0){
            return 1;
        }if(n==1){
            return x;
        }
        double res=pow(x,n/2);
        if(n%2==0){
            return res*res;
        }else{
            return res*res*x;
        }
    }
};