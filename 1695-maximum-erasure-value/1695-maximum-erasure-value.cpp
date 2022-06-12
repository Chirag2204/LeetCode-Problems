class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        vector<int> sum(nums.size());
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i]=nums[i]+sum[i-1];
        }
        map<int,int> m;
      
        int x=0, y=0;
        while(y<nums.size()){
            
            if(m.count(nums[y])){
                x=max(x,m[nums[y]]+1);  
             }
           m[nums[y]]=y;
            // cout<<x<<" "<<y<<endl;
            if(x==0)
            ans=max(ans,sum[y]);
            else
            ans=max(ans,sum[y]-sum[x-1]); 
            y++;
        }
        return ans;
    }
};