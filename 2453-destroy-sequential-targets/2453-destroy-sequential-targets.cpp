class Solution {
public:
    // int countnums(vector<int>& nums,int& space,int& x){
    //     int count=0;
    //      for(int i=0;i<nums.size();i++){
    //         if((nums[i]-x)%space==0)count++;
    //     }
    //     return count;
    // }
    
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int,int> m;//mod count
        int mx=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]%space]++;
            if(mx<m[nums[i]%space])mx=m[nums[i]%space];
        }
      
       
        int ans=1e9;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]%space]==mx)ans=min(ans,nums[i]);
        }
        return ans;
    }
};