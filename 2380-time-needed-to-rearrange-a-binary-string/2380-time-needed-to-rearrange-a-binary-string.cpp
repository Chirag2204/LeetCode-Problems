class Solution {
public:
    int countpairs(string& s){
        int c=0;
        for(int i=1;i<s.length();i++){
           if(s[i]=='1' and s[i-1]=='0')c++; 
        }
        return c;
    }
    int secondsToRemoveOccurrences(string s) {
        
        int count=0;
        while(countpairs(s)){
            // cout<<s<<" "<<countpairs(s)<<endl;
            count++;
            string temp=s;
            for(int i=1;i<s.length();i++){
            if(s[i]=='1' and s[i-1]=='0')swap(temp[i],temp[i-1]); 
          }
            s=temp;
        }
        return count;
    }
};