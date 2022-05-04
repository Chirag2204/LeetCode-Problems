class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int count=0;
        for(auto x:m){
            if(x.first<=k/2){
                if(x.first == k-x.first){
                   count+=min(x.second,m[k-x.first])/2; 
                }else
                count+=min(x.second,m[k-x.first]);
            }else break;
        }
        return count;
    }
};