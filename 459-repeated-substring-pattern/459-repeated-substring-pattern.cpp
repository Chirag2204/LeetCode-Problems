class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       int n=s.length();
        if(n==1)return false;
        vector<string> substrs;
        string str="";
        for(int i=0;i<n/2;i++){
            str.push_back(s[i]);
            substrs.push_back(str);
        }
        bool ans=false;
        for(int i=0;i<substrs.size();i++){
           
            if(n%substrs[i].length()==0){
                 ans=true;
                int x=0,y=0;
                while(y<n){
                    // cout<<substrs[i]<<endl;
                    if(x==substrs[i].length()){
                        x=0;
                    }
                    if(substrs[i][x]!=s[y]){
                      ans=false;
                        break;
                    } 
                    x++;
                    y++;
                }
                if(ans)return ans;
            }
        }
        return ans;
    }
};