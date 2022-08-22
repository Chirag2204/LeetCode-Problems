class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        if(n==INT_MIN)
            return false;
        int temp=abs(n);
        int count=0;
        while(temp){
            temp=temp>>1;
            count++;
        }
        if(((n&(n-1)) ==0 && (n&(n+1)) ==n)&&(count%2 != 0)){
            return true;
        }
        return false;
    }
};