class Solution {
public:
    bool isSquare(long long n){
        int root=sqrt(n);
        return root*root==n;
    }
    
    bool judgeSquareSum(long long c) {
        if(isSquare(c))return true;
       
        long long i=1;
        while(i*i<=c){
            if(isSquare(i*i) && isSquare(c-i*i))return true;
            i++;
        }
        return false;
    }
};