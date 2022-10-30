class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      //cout<<nums.size()<<endl;
        vector<int> myans(2);
        
      
        unordered_map<int,int>  hash;
        
        
        for(int i=0; i<nums.size() ; i++){
            myans[0]=i;
            if(hash.count(target-nums[i])){
                myans[1]=hash[target-nums[i]];
                break;            
            }
            hash[nums[i]]=i;
        }
        
        return myans;
    }
};