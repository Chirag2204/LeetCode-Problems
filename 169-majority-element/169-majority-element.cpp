class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
            if(umap[nums[i]]==n/2 + 1)
                return nums[i];
        }
        return -1;
    }
};