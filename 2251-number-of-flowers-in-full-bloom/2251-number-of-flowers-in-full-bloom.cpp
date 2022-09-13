class Solution {
public:
    //returns index of lower value and if not then return -1
    int getlowerstart(int val,vector<int>& nums){
       int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]<=val){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    int getlowerend(int val,vector<int>& nums){
       int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]<val){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n=flowers.size();
        vector<int> starts(n),ends(n);
        for(int i=0;i<n;i++){
            starts[i]=flowers[i][0];
            ends[i]=flowers[i][1];
        }
        
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        vector<int> ans;
        for(int i=0;i<persons.size();i++){
            int start=getlowerstart(persons[i],starts);
            int end=getlowerend(persons[i],ends);
            ans.push_back(start-end);
        }
        return ans;
    }
};