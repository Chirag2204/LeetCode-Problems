class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int , int> m;
        sort(nums.begin(),nums.end());
        for(int& i:nums)m[i]++;
        for(int& i:nums){
            if(m[i]>0){
             
                for(int j=1;j<k;j++){
                    if(!m.count(i+j) or m[i+j]<m[i])return false;
                    m[i+j]-=m[i];
                } 
                   m[i]=0;
            }
          
        }
       
        return true;
    }
};