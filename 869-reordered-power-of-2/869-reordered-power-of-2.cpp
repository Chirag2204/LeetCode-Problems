class Solution {
public:
    int getcount(int n){
        int count=0;
        while(n){
           count+=pow(10,n%10);
            n/=10;
        }
        return count;
    }
    bool reorderedPowerOf2(int n) {
        int c=getcount(n);
       for(int i=0;i<32;i++){
           if(getcount(1<<i) == c)return true;
       }
        return false;
    }
};