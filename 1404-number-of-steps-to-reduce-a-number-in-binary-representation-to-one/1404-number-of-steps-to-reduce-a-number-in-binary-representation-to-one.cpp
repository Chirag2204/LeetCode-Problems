class Solution {
public:
    void addOne(string& s){
        bool done=false;
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]=='0'){
                s[i]='1';
                s[s.length()-1]='0';
                done=true;
                break;
            }   
        }
        if(!done){
            s[0]='1';
            for(int i=1;i<s.length();i++){
               s[i]='0'; 
            }
            s.push_back(0);
        }
    }
    
    int numSteps(string s) {
        int count=0;
        while(s.length()>1){
            if(s[s.length()-1]=='1'){
                addOne(s);
                count++;
            }
            else {
                 count++;
            s.pop_back();
            }  
        }
        return count;
    }
};