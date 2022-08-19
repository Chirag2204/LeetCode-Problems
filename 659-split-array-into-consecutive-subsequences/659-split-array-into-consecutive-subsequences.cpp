class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)return false;
        unordered_map<int,int> m;
        for(int& i:nums)m[i]++;
        
        unordered_map<int,int> endhere;
        for(int& i:nums){
            if(m[i]==0)continue;
            
            m[i]--;//took it into some sequence
            
            if(endhere[i-1]>0){//any sequence ends at i-1
                endhere[i-1]--;
                endhere[i]++;//now that sequence ends at i
            }else if(m[i+1]>0 and m[i+2]>0){
                    m[i+1]--;
                    m[i+2]--;
                    endhere[i+2]++;//new sequnce ends at i+2
            }else{
                return false;
            }
                        
        }
        return true;
    }
};