class Solution {
public:
    int mod=1e9+7;
    int power(int a ,int b){
        if(a==0 or a==1)return a;
        if(b==0)return 1;
        if(b==1)return a;
        
        long long  p=power(a,b/2)%mod;
        
        if(b%2)return ((a%mod)*(p%mod)*(p%mod))%mod;
        
        return ((p%mod)*(p%mod))%mod;
        
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        bitset<32> b1(n);
        vector<int> powers;
        for(int i=0;i<32;i++){
            if(b1[i]==1)powers.push_back(i);
        }
        int num=0;
        for(int i=1;i<powers.size();i++){
            num=powers[i-1]+powers[i];
            powers[i]=num;
        }
        vector<int> ans;
        for(auto& q:queries){
            num=powers[q[1]];
            if(q[0]>0)num-=powers[q[0]-1];
            int x=power(2,num);
            ans.push_back(x%mod);
        }
        return ans;
    }
};