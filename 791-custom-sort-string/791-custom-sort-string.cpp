class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        for(int i=0;i<26;i++){
            m[char(97+i)]=0;
        }
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.length();i++){
            if(m[order[i]]!=0){
                while(m[order[i]]){
                ans.push_back(order[i]);
                m[order[i]]--;
                }
            }
        }
        for(auto x:m){
            for(int i=0;i<x.second;i++){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};