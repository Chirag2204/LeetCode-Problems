class Solution {
public:
    bool isPerfectSquare(int num) {
        int max=0;
        if(num==1){
            return true;
        }
       for(long i=1;i <= num/2 ; i++){
          if(i*i == num){
              max=i;
              break;
          } 
       }
        if(max>0){
            return true;
        }else{
          return false;  
        }
          
    }
};