class Solution {
public:
    int minOperations(int n) {
        if(n==1)return 1;
        bitset<32> num(n);
        int ans=0;
        int count=0;
        for(int i=0;i<32;i++){
            if(num[i]==1){
              count++;
            }else{
                if(count>1){
                    ans++;
                    count=1;
                }
                else if(count==1){
                    ans++;
                    count=0;
                }
            }
        }
        return ans;
       
    }
};