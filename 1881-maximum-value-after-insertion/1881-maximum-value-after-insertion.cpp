class Solution {
public:
    string maxValue(string n, int x) {
        string ans="";
        bool pushed=false;
        if(n[0]=='-'){
            ans.push_back('-');
           
          for(int i=1;i<n.length();i++){
              if(int(n[i]-48)>x && !pushed){
                 ans.push_back(char(x+48));
                  pushed=true;
              }
              ans.push_back(n[i]);
          }  
        }else{
            for(int i=0;i<n.length();i++){
              if(int(n[i]-48)<x && !pushed){
                  ans.push_back(char(x+48));
                  pushed=true;
                 
              }
                ans.push_back(n[i]);
           }
        }
        if(!pushed)ans.push_back(char(x+48));
       return ans; 
    }
};