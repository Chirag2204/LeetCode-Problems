class Solution {
public:
    int hammingWeight(uint32_t u) {
        int count=0;
        while(u){
            u=u&u-1;
            count++;
        }
        return count;
    }
};