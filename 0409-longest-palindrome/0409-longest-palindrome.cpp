class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        
        for(char& c:s){
            m[c]++;
        }
        int len=0;
        int mx=0;
        char mxchar='a';
        for(auto& i:m){
            //cout<<i.second<<endl;
            if(i.second%2){
               if(mx<i.second){
                   mxchar=i.first;
                   mx=i.second;
               }
            }
            else len+=i.second;
        }
        for(auto& i:m){
            
            if(i.second%2 and i.first!=mxchar)len+=i.second-1;
            
        }
        return len+mx;
    }
};