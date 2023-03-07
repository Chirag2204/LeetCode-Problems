class Solution {
public:
    int splitNum(int num) {
       string s=to_string(num);
        
       sort(s.begin(),s.end());
       int num1=0,num2=0;
        
       for(int i=0;i<s.length();i+=2)num1=num1*10 + (s[i]-48);
       for(int i=1;i<s.length();i+=2)num2=num2*10 + (s[i]-48);
        
        return num1+num2;
       
        
    }
};