class Solution {
public:
    bool check(map<char,set<char>>& m,vector<int>& vis,char& a,char& b){
        queue<char> q;
        q.push(a);
        vis[a-97]=1;
        while(!q.empty()){
            char c=q.front();
            q.pop();
            
            for(auto& i: m[c]){
                if(i==b){
                   vis.resize(26,0);
                   return false; 
                }
                if(!vis[i-97]){
                    vis[i-97]=1;
                    q.push(i);
                }
            }
        }
        for(int i=0;i<26;i++)vis[i]=0;
        return true;
    }
    
    bool equationsPossible(vector<string>& eq) {
        map<char,set<char>> m;
        vector<int> vis(26,0);
        for(string& s:eq){
            if(s[1]=='='){
              m[s[0]].insert(s[3]);
              m[s[3]].insert(s[0]);  
            }
        }
        
        for(string& s:eq){
            if(s[1]=='!'){
                if(s[0]==s[3])return false;
               if(!check(m,vis,s[0],s[3]))return false;   
            }
        }
        return true;
    }
};