class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length()==1)return "";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(n%2 and i==n/2)continue;
            if(s[i]!='a'){
                s[i]='a';
                break;
            }
            if(i==n-1){
                s[i]='b';
            }
        }
        return s;
    }
};