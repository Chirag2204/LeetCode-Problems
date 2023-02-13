class Solution {
public:
    int countOdds(int low, int high) {
        if(high==low)return high%2;
        
        if(high%2==0 and low%2==0)return (high-low)/2;
        return (high-low)/2 +1;
    }
};