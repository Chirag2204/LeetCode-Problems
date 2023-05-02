class Solution {
public:
    int mod=1337;
    long long power(long long a,long long b){
        if(a==1 or b==0)return 1;
        if(b==1)return a;
        
        long long p=power(a,b/2)%mod;
        if(b%2)return ((a%mod)*(p%mod)*(p%mod))%mod;
        return ((p%mod)*(p%mod))%mod;
    }
    
    int solve(int &a,vector<int>& b,int count,int& n){
        if(n==count)return 1;
        return (int)((int)(power(solve(a,b,count+1,n),10)%mod)*(int)( power(a,b[n-count-1])%mod))%mod;
    }
    int superPow(int a, vector<int>& b) {
        int n=b.size();
        return solve(a,b,0,n)%mod;
    }
};