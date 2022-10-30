class Solution {
public:
    int climbStairs(int n) {
       return climb(n); 
    }
    
    int climb(int n){
        if(n<=0){
            return 0;
        }
        if( n==1){
            return 1;
        }
       long a=0,b=1,count=1,c;
        while(count<=n){
            c=a+b;
            a=b;
            b=c;
            count++;
        }
        return c;
        
    }
};