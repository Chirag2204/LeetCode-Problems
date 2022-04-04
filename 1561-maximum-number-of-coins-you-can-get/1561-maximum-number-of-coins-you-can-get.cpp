class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=piles.size()-2,q=0;
        int sum=0;
        while(i>=q){
           
            sum+=piles[i];
            i-=2;
            q++;
        }
        return sum;
    }
};