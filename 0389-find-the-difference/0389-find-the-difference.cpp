class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v1(26,0),v2(26,0);
        for(int i=0;i<s.length();i++){
            v1[int(s[i])-97]++;
        }
        for(int i=0;i<t.length();i++){
            v2[int(t[i])-97]++;
        }
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i])
                return char(i+97);
        }
        return 'a';
    }
};