class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
            ans+=1+min(last[0],min(last[1],last[2]));
        }
        return ans;
    }
};