class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(),dict.end(),mysort);
        
        for(string& str: dict){
            int j=0;
            for(char& c:s){
                if(c==str[j])j++;
                if(j==str.length())return str;
            }
        }
        return "";
    }
    
    static bool mysort(string& a,string &b){
        if(a.length()==b.length()){
            return a<b;
        }
        return a.length()>b.length();
    }
};