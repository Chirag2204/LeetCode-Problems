class Solution {
public:
    vector<vector<string>> ans;
    
    void solve(string& s,int index,vector<string> temp){
        if(index==s.length()){
            if(temp.size())
            ans.push_back(temp);
        }else{
            for(int i=index;i<s.length();i++){
                if(isPalindrome(s.substr(index,i-index+1))){
                    temp.push_back(s.substr(index,i-index+1));
                    solve(s,i+1,temp);
                    temp.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
    
    bool isPalindrome(string s){
        string str=s;
        reverse(s.begin(),s.end());
        return s==str;
    }
};