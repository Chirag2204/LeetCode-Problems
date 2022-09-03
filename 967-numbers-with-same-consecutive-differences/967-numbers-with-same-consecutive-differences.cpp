class Solution {
public:
    void solve(string& s,int &n,int& k,int prev,vector<int>& ans){
        if(s.length()==n){
           ans.push_back(stoi(s));
            return; 
        }
            
        
        for(int i=0;i<=9;i++){
            if(prev==-1){
                if(i!=0){
                    s.push_back(i+48);
                    solve(s,n,k,i,ans);
                    s.pop_back();
                }
            }
            else{
                if(abs(prev-i)==k){
                    s.push_back(i+48);
                    solve(s,n,k,i,ans);
                    s.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string s="";
        solve(s,n,k,-1,ans);
        return ans;
    }
};