class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count (26);
        if(s.length()!=t.length())
            return false;
        int n=s.length();
        for(int i=0;i<s.length();i++){
            count[int(s[i])-97]++;
            count[int(t[i]-97)]--;
        }
        for(int i=0;i<26;i++){
            if(count[i])
                return false;
        }
        return true;
    }
};