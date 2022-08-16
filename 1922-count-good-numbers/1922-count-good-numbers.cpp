class Solution {
public:
    int mod=1000000007;
    long long power(int a,long long b){
        if(b==1)return a;
        if(b==0)return 1;
        long long p=power(a,b/2);
        if(b%2){
            return (a*(p%mod)*(p%mod))%mod;
        }
        return ((p%mod)*(p%mod))%mod;
    }
   
    int countGoodNumbers(long long n) {
        long long ans=1;
        if(n%2){
            ans=5*(power(5,n/2)%mod)*(power(4,n/2)%mod)%mod;
        }
        else
            ans=(power(5,n/2)%mod)*(power(4,n/2)%mod)%mod;
        
        return (int)ans;
    }
};