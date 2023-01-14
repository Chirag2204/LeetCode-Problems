class Solution {
public:
    char minc(char &a,char& b){
        if(a<b)return a;
        return b;
    }
    void dfs(char &mn,char c,map<char,vector<char>>& m,vector<int>& vis){
        if(!vis[c-97]){
            vis[c-97]=1;
            mn=minc(mn,c);
            for(auto& x:m[c]){
                dfs(mn,x,m,vis);
            }
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char,vector<char>> m;
        
        for(int i=0;i<s1.length();i++){
           m[s1[i]].push_back(s2[i]);
           m[s2[i]].push_back(s1[i]);
        }
       
        string ans="";
        vector<int> vis(26,0);
        for(char c:baseStr){
            char mn=c;
            dfs(mn,c,m,vis);
            for(int i=0;i<26;i++)vis[i]=0;
            ans.push_back(mn);   
        }
        return ans;
    }
};