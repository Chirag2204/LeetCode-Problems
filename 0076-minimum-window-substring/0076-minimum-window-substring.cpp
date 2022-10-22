class Solution {
public:
    bool check(map<char,int>& m1,map<char,int>& m2){
        for(auto& x:m1){
            if(!m2.count(x.first) or m2[x.first]<x.second)return false;
        }
        return true;
    }
    
    string minWindow(string s, string p) {
       map<char,int> m1;
       map<char,int> m2;
        
        for(char& c:p){
            m1[c]++;
        }
        
        int i=0;
        while(i>=0 and i<s.length() and !m1.count(s[i]))i++;
        
        int j=i;
        int len=1e9;
        int start=0;
        string ans="";
        while(j<s.length()){
            m2[s[j]]++;
            while(check(m1,m2)){
                if(len>j-i+1){
                    start=i;
                    len=j-i+1;
                }
                m2[s[i]]--;
                i++;
            }
            j++;
        }
        if(len==1e9)return ans;
        ans=s.substr(start,len);
        return ans;
    }
};