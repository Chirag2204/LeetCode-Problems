class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        nums.clear();
        for(auto x:m){
            for(int i=0;i<x.second;i++){
                nums.push_back(x.first);
            }
        }
        
    }
};