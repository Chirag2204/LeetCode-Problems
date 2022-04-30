class Solution {
public:
    int minSwaps(string s) {
        int i=0,j=s.length()-1,count=0,count1=0;
        while(i<=j){
            
            if(s[i]=='['){
                count1++;
            }else{
                
                count1--;
            }
            if(count1<0){
              
              while(s[j]!='['){
              j--;
              }
             if(j>i){
               swap(s[i],s[j]);
               count++;  
               count1=1; 
             }
            }
                i++;
               
                
        }
        return count;
    }
};