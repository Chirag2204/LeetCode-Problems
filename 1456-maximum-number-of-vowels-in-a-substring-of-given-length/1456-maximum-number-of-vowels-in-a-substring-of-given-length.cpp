class Solution {
public:
    int maxVowels(string s, int k) {
        int max=0 ,count=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i]))
                count++;
            if(i>=k){
                // cout<<i<<" "<<i-k<<" "<<s[i-k]<<endl;
                if(isVowel(s[i-k]))
                    count--;
            }
            if(max<count)
                max=count;
        }
        
        return max;
    }
    
    int isVowel(char s){
       return (s=='a' ||s=='e' ||s=='i' ||s=='o' ||s=='u' );
            
    }
};