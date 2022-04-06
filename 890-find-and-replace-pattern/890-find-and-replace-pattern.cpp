class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            bool push=true;
            unordered_map<char,char> umap1;
            unordered_map<char,char> umap2;
            for(int j=0;j<words[i].length();j++){
                //cout<<words[i][j]<<" "<<pattern[j]<<endl;
                if(umap1.count(words[i][j]) && umap1[words[i][j]]!=pattern[j]){
                    push = false;
                    break;
                }else{
                    // cout<<"new element in umap1"<<endl;
                    umap1[words[i][j]]=pattern[j];
                }
                 if(umap2.count(pattern[j]) && umap2[pattern[j]]!=words[i][j]){
                    push = false;
                    break;
                }else{
                     // cout<<"new element in umap2"<<endl;
                    umap2[pattern[j]]=words[i][j];
                }
                // cout<<push<<endl;
            }
            if(push){
                ans.push_back(words[i]);
            }
            //cout<<"-------------------------"<<endl;
        }
        return ans;
        
    }
};