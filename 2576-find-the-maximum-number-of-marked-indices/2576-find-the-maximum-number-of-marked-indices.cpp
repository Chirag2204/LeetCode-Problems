class Solution {
public:
    bool isPossible(vector<int>& nums,int k){
        int i=0,j=k;
        //if(nums.size()%2==0)j++;
        int count=0;
        while(j<nums.size() and i<k){

            if(2*nums[i]<=nums[j]){
                count++;
                i++;
            }
            j++;
        }
        return count==k;
    }
    
    int maxNumOfMarkedIndices(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int s=0,e= nums.size()/2;
       // cout<<s<<" "<<e<<endl;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            //cout<<mid<<" ";
            if(isPossible(nums,mid)){
                ans=mid;
                //cout<<ans;
                s=mid+1;
            }else e=mid-1;
            //cout<<endl;
            mid=s+(e-s)/2;
        }
        return ans*2;
    }
};