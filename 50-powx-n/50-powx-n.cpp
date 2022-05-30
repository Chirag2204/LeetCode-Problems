class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0){
            return 1;
        }
        double pow;
        if(n<0){
             n = -n;
            x = 1/x;
        }
        if(n%2==0){
            x=abs(x);
        }
        pow=myPow(x*x,n/2);
        if(n%2==0){
            return pow;
        }else{
            return x*pow;
        }
    }
};

/*
 if(n == 0)
            return 1;
        if(n<0){
            n = -n;
            x = 1/x;
        }
        return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);*/