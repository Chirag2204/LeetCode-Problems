class Solution {
public:
    void solve(vector<string>& ans,int index,string s){
        if(index==s.size()){
            ans.push_back(s);
            return ; 
        }
          //do not convert
           solve(ans,index+1,s);
        //convert
        if(isalpha(s[index])){
         if(s[index]<97){
             s[index]+=32;
         }else
            s[index]-=32;
         solve(ans,index+1,s);
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>  ans;
        solve(ans,0,s);
        return ans;
    }
};