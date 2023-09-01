class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<=n;i++){
           int temp=i;
            int count=0;
            while(temp!=0){
                int mod=temp%2;
                temp=temp/2;
                if(mod==1){
                    count++;
                    mod=0;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};