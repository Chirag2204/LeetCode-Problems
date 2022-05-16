class Solution {
public:
    int minFlips(string target) {
        int groups=0;
        char prev=target[0];
        for(int i=0;i<target.size();i++){
            if(groups==0){
                if(target[i]=='1'){
                    groups=1;
                    prev='1';
                }
            }else{
               if(target[i]!=prev){
                   groups++;
                   prev=target[i];
               } 
            }
        }
        return groups;
    }
};