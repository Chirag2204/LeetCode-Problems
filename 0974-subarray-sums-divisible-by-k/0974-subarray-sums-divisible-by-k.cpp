class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> m;
        int ans=0;
        int sum=0;
        //for(int i=0;i<nums.size();i++)nums[i]+=k;
        
        for(int i=0;i<nums.size();i++){
          
            sum=(sum+nums[i]%k +k);
            
            if(abs(sum)%k==0){
                ans+=m[abs(sum)%k]+1;
            }
            else
            ans+=m[abs(sum)%k];
            
            m[abs(sum)%k]++;
           // cout<<i<<" "<<sum<<" "<<m[sum%k]<<endl;
        }
        return ans;
    }
};