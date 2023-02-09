class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        
        vector<unordered_set<string>> m(26);
        
        for(string& s:ideas)m[s[0]-'a'].insert(s.substr(1,s.length()-1));
        long long c1=0,c2=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                c1=0,c2=0;
                for(auto& s:m[i]){
                    //cout<<char(i+97)<<" "<<s<<endl;
                    if(!m[j].count(s))c1++;
                }
                
                for(auto& s:m[j]){
                    //cout<<char(j+97)<<" "<<s<<endl;
                    if(!m[i].count(s))c2++;
                }
                ans+=c1*c2;
            }
        }
        return ans*2;
    }
};