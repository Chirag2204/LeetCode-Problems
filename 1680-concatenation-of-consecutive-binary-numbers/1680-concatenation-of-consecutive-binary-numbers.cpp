class Solution {
public:
    
    
    int concatenatedBinary(int n) {
        int mod=1e9+7;
        long long ans=0;
        for(int i=1;i<=n;i++){
            int bits=log2(i)+1;
            ans=((ans<<bits)%mod + i)%mod;
        }
        return int(ans);
    }
};