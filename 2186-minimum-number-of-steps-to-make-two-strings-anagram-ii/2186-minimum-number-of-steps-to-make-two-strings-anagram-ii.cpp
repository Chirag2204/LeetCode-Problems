class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        for(char& c: s){
            m1[c]++;
        }
        
         for(char& c: t){
            m2[c]++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            count+=abs(m1[char(97+i)]-m2[char(97+i)]);
        }
        return count;
    }
};