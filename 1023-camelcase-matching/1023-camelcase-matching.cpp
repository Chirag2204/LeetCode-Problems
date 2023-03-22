class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
         vector<bool> ans;
         int i=0;
        bool push=false,foundcap=false;
        for(string& s:queries){
            i=0;
            push=false;
            foundcap=false;
            for(char& c:s){
                if(i==pattern.size() and c>=65 and c<=90)foundcap=true;
                if(c>=65 and c<=90 and c!=pattern[i]){
                    push=false;
                    break;
                }
                if(c==pattern[i])i++;
                
                if(i==pattern.size())push=true;
                
            }
            //cout<<s<<" "<<foundcap<<" "<<push<<endl;
            ans.push_back(push && !foundcap);
        }
        return ans;
    }
};