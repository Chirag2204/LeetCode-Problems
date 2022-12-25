class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        vector<int> ans;
        bool pushed=false;
        for(int i=0;i<queries.size();i++){
           for(int j=0;j<nums.size();j++){
               pushed=false;
               if(nums[j]>queries[i]){
                   ans.push_back(j);
                   pushed=true;
                   break;
              }
               
           }
            if(!pushed)ans.push_back(nums.size());
        }
        return ans;
    }
};