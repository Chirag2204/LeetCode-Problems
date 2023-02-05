class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        int mod=1e9+7;
        
        long long n=0;
        for(char& c:s){
            if(c=='1'){
                n++;
            }else{
                //cout<<n<<endl;
                ans+= n*(n+1)/2;
                n=0;
                ans%=mod;
            }
        }
        //cout<<n<<endl;
        ans+= n*(n+1)/2;
        ans%=mod;
        return (int)ans;
    }
};