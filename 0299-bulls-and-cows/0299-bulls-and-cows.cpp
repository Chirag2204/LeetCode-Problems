class Solution {
public:
    string getHint(string secret, string guess) {
       int b=0,c=0;
        
        map<char,int> ma,mb;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i])b++;
            else{
                ma[secret[i]]++;
                mb[guess[i]]++;
            }
            
        }
        
        for(int i=48;i<=58;i++){
            c+=min(ma[i],mb[i]);
        }
        return to_string(b)+"A"+to_string(c)+"B";
    }
};