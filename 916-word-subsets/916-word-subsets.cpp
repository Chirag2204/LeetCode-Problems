class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> collect(26,0);
        for(string& s:words2){
            vector<int> temp1(26,0);
            for(char& c:s){
                temp1[c-97]++;
            }
            for(int i=0;i<26;i++){
                collect[i]=max(temp1[i],collect[i]);
            }
        }
        for(string &s:words1){
            vector<int> temp(26,0);
            for(char& c:s){
                temp[c-97]++;
            }
            bool include=true;
            // cout<<s<<endl;
            for(int i=0;i<26;i++){
                // cout<<i<<" "<<temp[i]<<" "<<collect[i]<<endl;
                if(temp[i]<collect[i]){
                    include=false;
                    break;
                }
            }
            // cout<<endl;
            if(include)ans.push_back(s);
        }
        return ans;
    }
};