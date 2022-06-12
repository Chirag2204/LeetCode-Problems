class Solution {
public:
    int arrangeCoins(int n) {
        int ans=0;
        int count=1;
        while(n>0){
            n=n-count;
            if(n>=0)
                ans++;
            count++;
        }
        return ans;
    }
};