class Solution {
public:
    bool validPalindrome(string s) {
        int p=0,q=s.size()-1;
        int count1=0,count2=0;
        while(p<=q){
            if(s[p]!=s[q]){
               count1++;
                if(count1>1)
                    break;
                q--;
            }else{
                p++;
                q--;
            }
        }
        
          p=0;q=s.size()-1;
        while(p<=q){
            if(s[p]!=s[q]){
               count2++;
                if(count2>1)
                    break;
                p++;
            }else{
                p++;
                q--;
            }
        }
        return (min(count1,count2)<=1);
    }
};