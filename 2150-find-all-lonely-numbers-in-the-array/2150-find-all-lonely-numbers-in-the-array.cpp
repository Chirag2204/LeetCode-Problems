class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> m;
        for(int& i:nums)m[i]++;
        vector<int> count;
        for(auto& x:m){
            if(x.second==1 and !m.count(x.first-1) and !m.count(x.first+1) )count.push_back(x.first);
        }
        return count;
    }
};