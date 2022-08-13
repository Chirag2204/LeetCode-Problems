class Solution {
public:
    int find(vector<int>& nums,int s,int e,int req){
       int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]>=req){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int req=nums[i]+nums[j];
                auto beg=nums.begin()+j;
                int x=(lower_bound(beg,nums.end(),req)-nums.begin())-j;
                if(x>0)
                ans+=x-1;
            }
        }
        return ans;
    }
};