class Solution {
public:
    vector<int> vec;
    int f(int n){
        vector<int> num;
        while(n>0){
            num.push_back(n%10);
            n/=10;
        }
        if(num.size()==0)num.push_back(0);
        reverse(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            num[i]=vec[num[i]];
            n=n*10 + num[i];
        }
        return n;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       
        vec=mapping;
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++){
           pairs.push_back(make_pair(f(nums[i]),i));
        }
        sort(pairs.begin(),pairs.end());
        vector<int> ans;
        for(int i=0;i<pairs.size();i++){
            ans.push_back(nums[pairs[i].second]);
        }
        
        return ans;
    }
    
};