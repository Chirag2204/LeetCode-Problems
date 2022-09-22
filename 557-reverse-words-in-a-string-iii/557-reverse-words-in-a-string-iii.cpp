class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int count=0,start=-1;
        for(int i=0;i<s.size();i++){
           if(s[i]==' ' ){
               ans.append(reverse(s.substr(start,count)));
               ans.push_back(' ');
               start=-1;
               count=0;
           }
           
            else{
               if(start==-1)
                   start=i;
               count++;
           }
            
             if(i==s.size()-1){
                 ans.append(reverse(s.substr(start,count)));
            }
        }
            return ans;
    }
    
    string reverse(string s){
        char swap;
        int i=0,j=s.size()-1;
        while(i<j){
           swap=s[i];
            s[i]=s[j];
            s[j]=swap;
            i++;
            j--;
        }
        return s;
    }
};