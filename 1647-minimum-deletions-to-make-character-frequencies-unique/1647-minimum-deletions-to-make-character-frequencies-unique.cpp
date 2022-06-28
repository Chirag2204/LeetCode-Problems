class Solution {
public:
    int minDeletions(string s) {
       map<char,int> m;
        for(int i=0;i<s.length();i++){
           m[s[i]]++;
        }
        map<int,int,greater<int>> count;
        for(auto& x:m){
            count[x.second]++;
        }
        int ans=0;
        for(auto &x:count){
           int n=x.second;
           if(x.first>0 && x.second>0){
               ans+=n-1;
               count[x.first-1]+=n-1;
           }
            
        }
        return ans;
    }
};