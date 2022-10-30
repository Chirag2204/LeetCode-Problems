class Solution {
public:
    string solve(string &s , int &i){
        string ans="";
        
        while(i<s.length() and s[i] != ']'){
           if(!isdigit(s[i]) )ans.push_back(s[i++]);
            else{
                int n=0;
                while(i<s.length() and isdigit(s[i])){
                    n=n*10 + s[i++]-48;
                }
                i++;
                string str=solve(s,i);
                i++;
              
                while(n>0){
                    ans+=str;
                    n--;
                }
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int i=0;
        
        return solve(s,i);
    }
};