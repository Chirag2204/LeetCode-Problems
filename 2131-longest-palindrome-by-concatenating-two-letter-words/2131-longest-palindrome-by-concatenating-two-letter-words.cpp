class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        for(string& s:words)m[s]++;
        
        int ans=0;
        bool odd=false;
        for(auto& x:m){
            string s=x.first;
            if(s[0]==s[1]){
               if(x.second%2==0)ans+=2*x.second;
                else {
                    ans+=2*(x.second-1);
                    odd=true;
                }
            }else{
               string temp=s;
               reverse(temp.begin(),temp.end());
               if(m.count(temp) and m[temp]>0){
                   int count=min(m[s],m[temp]);
                   ans+=2*count;
               }
            }
  
        }
        if(odd)ans+=2;
        return ans;
    }
};