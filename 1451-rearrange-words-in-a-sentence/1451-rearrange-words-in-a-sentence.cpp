class Solution {
public:
    string arrangeWords(string text) {
        vector<string> v;
        string s="";
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                v.push_back(s);
                s.clear();
            }else{
                s.push_back(text[i]);
            }
        }
        v.push_back(s);
        map<int,vector<string>> m;
        for(string& str:v){
            m[str.length()].push_back(str);
        }
        v.clear();
        for(auto& x:m){
            for(string& i:x.second){
                v.push_back(i);
            }
            
        }
        
        string ans="";
        for(int i=0;i<v.size();i++){
            if(v[0][0]>=97)v[0][0]-=32;
            if(i!=0 and v[i][0]<=90)v[i][0]+=32;
            
            ans.append(v[i]);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
    
    // static bool mysort(string& a,string& b){
    //     if(a.length()==b.length())return true;
    //     return a.length()<b.length();
    // }
};