class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)sum+=nums[i];
        }
        vector<int> ans;
        for(auto& v:queries){
            if(nums[v[1]]%2==0){
                int temp=nums[v[1]];
                nums[v[1]]+=v[0];
                if(nums[v[1]]%2==0){
                    sum+=v[0];
                }else{
                    sum-=temp;
                }
            }else{
                nums[v[1]]+=v[0];
                if(nums[v[1]]%2==0){
                    sum+=nums[v[1]];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};