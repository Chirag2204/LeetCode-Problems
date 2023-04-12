class Solution {
public:
    string simplifyPath(string path) {
        vector<string> strs1;
        vector<string> strs2;
        
        string s="";
        for(char& c:path){
            if(c=='/'){
                strs1.push_back(s);
                s="";
            }else s.push_back(c);            
        }
        if(s.length())strs1.push_back(s);
        string ans="";
        
        for(string& s1:strs1){
            //cout<<s1<<endl;
            if(s1=="." or s1=="")continue;
            
            if(s1==".." and strs2.size())strs2.pop_back();
            else if(s1!="..") strs2.push_back(s1);
        }
        
        for(string& s1:strs2){
            //cout<<s1<<endl;
            ans+="/"+s1;}
        if(ans=="")return "/";
        return ans;
    }
};
/*
"/home/"
"/../"
"/home//foo/"
*/