class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s="";
        string ans="";
        bool found1=true,found2=true;
        for(int i=0;i<min(str1.length(),str2.length());i++){
            found1=true,found2=true;
            if(str1[i]==str2[i]){
                s.push_back(str1[i]);
                if(str1.length()%s.length()==0 and str2.length()%s.length()==0){
                    for(int j=0;j<str1.length();j+=s.length()){
                       if(s!=str1.substr(j,s.length())){
                           found1=false;
                           break;
                       }
                    }
                    for(int j=0;j<str2.length();j+=s.length()){
                       if(s!=str2.substr(j,s.length())){
                           found2=false;
                           break;
                       }
                    }
                    if(found1 and found2)ans=s;
                }
                
            }else break;
   
        }
        return ans;
    }
};