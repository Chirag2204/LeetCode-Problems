class Solution {
public:
    int countHousePlacements(int n) {
       long long a=1,b=1,c;
        n++;
        while(n--){
            c=a%1000000007+b%1000000007;
            a=b%1000000007;
            b=c%1000000007;
        }
        return ((a%1000000007)*(a%1000000007))%1000000007;
    }
};