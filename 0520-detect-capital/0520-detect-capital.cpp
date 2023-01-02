class Solution {
public:
    bool detectCapitalUse(string word) {
        int countc=0,counts=0;
        for(int i=0;i<word.length();i++){
            if(int(word[i])<97)
                countc++;
            else
                counts++;    
          }
        if(counts==0 || countc==0)
            return true; 
        
         if(countc!=0 && counts!=0){
           if(countc==1 && int(word[0])<97){
               return true;
           }else{
               return false;
           }       
        }
        return false;
        }   
};