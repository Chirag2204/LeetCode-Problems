class Solution {
public:
    int mySqrt(long x) {
        if(x==1){
            return 1;
        }
       int s=0,e=x;
        int ans;
        long long int m=s+(e-s)/2;
        while(s<=e){
            if(m*m==x){
                return m;
            }
            if(m*m>x){
                e=m-1;
            }
            if(m*m<x){
                ans=m;
                s=m+1;
            }
           m=s+(e-s)/2;
        }
        return ans;
    }
};