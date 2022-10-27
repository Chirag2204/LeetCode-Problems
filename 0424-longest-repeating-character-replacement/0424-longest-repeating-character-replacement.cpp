class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        for(int c=65;c<=90;c++){
            //cout<<char(c)<<endl;
            int i=0,j=0;
            int count=0;
            while(j<s.length()){
                if(s[j] != char(c)){
                    count++;
                    if(count>k){
                        while(s[i]==char(c))i++;
                        i++;
                        count--;
                    }
                }
                ans=max(ans,j-i+1);
                if(ans==s.length())return ans;
                j++;
                
            }
        }
        return ans;
    }
};