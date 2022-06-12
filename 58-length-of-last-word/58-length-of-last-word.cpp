class Solution {
public:
    int lengthOfLastWord(string s) {
         int slength=0;
         int counts=0;
        for(int i = s.length()-1 ; i>=0 ; i--){
           if(s[i]==' '){
                   if(slength==0){
                           counts++;
                   }else{
                           break;
                   }
           }else{
                   slength++;
           }
        }
            return slength;
    }
};