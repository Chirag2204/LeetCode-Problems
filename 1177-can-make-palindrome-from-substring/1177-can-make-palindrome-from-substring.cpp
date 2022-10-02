class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        map<int,vector<int>> m;// index freq
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-97]++;
            m[i]=count;
        }
        vector<bool> ans;
        vector<int> check(26,0);
        for(auto& x: queries){
            int start=x[0];
            int end=x[1];
            int sub=x[2];
            if(start==0)check=m[end];
            else{
                for(int i=0;i<26;i++){
                    check[i]=m[end][i]-m[start-1][i];
                }
            }
            int odd=0;
            for(int i=0;i<26;i++){
                if(check[i]%2)odd++;
               
            }
            if(odd<=1 or(odd/2<=sub))ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};