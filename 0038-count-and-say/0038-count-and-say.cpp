class Solution {
public:
    string solve(int n,string s){
        if(n==1)return s;
        int i=0;
        int len=s.length();
        string res="";
        while(i<len){
            int j=i;
            while(i<len and s[i]==s[j])i++;
            
            res+=to_string(i-j)+s[j];
        }
        
        return solve(n-1,res);
    }
    string countAndSay(int n) {
        string s="1";
        return solve(n,s);
    }
};