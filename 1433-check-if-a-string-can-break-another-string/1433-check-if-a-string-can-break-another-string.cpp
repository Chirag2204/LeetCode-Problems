class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        bool s1b=true,s2b=true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
     
        
        for(int i=0;i<s1.length();i++){
            if(s2[i]<s1[i])
            {
                s2b=false;
                break;
            }
        }
        
        for(int i=0;i<s1.length();i++){
            if(s1[i]<s2[i])
            {
                s1b=false;
                break;
            }
        }
        return s1b || s2b;
    }
    
};