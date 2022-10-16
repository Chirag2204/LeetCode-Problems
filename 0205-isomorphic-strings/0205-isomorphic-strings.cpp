class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        map<char,char> m;
        map<char,char> m1;
        for(int i=0;i<s.length();i++){
            if((m.count(s[i]) and m[s[i]]!=t[i]) or (m1.count(t[i]) and m1[t[i]]!=s[i]))return false;
            m[s[i]]=t[i];
            m1[t[i]]=s[i];
        }
        return true;
    }
};