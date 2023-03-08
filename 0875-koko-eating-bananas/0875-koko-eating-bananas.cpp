class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int max=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>max)
                max=piles[i];
        }
        int low = 1, high = max, k = 0;
        while (low <= high) {
            k = low+(high-low)/ 2;
            long long h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            if (h > H)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;
    }
};