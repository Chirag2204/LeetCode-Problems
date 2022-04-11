class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        int sum=0;
        for(int i=97;i<123;i++){
            sum+=abs(m1[char(i)]-m2[char(i)]);
        }
        if(sum%2) return sum/2 + 1 ;
        else return sum/2;
    }
};