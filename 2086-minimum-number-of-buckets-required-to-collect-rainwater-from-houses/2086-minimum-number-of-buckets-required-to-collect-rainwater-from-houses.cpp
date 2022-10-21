class Solution {
public:
    int minimumBuckets(string street) {
        if(street.length()==1){
            if(street[0]=='H')return -1;
            return 0;
        }
        for(int i=0;i<street.length();i++){
            if(street[i]=='H'){
                if(i>0 and street[i-1]=='B')continue;
                if(i<street.length()-1 and street[i+1]!='H')street[i+1]='B';
                else{
                    if(i>0 and street[i-1]=='H')return -1;
                    if(i>0)
                    street[i-1]='B';
                    else return -1;
                }
            }
        }
        
        int ans=0;
        for(char& c:street){
            if(c=='B')ans++;
        }
        return ans;
    }
};