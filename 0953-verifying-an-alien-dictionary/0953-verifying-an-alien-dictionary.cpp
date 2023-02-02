class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        
        for(int i=0;i<order.length();i++){
            m[order[i]]=i;
        }
        
        bool ans=true;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<min(words[i].length(),words[i-1].length());j++){
                //cout<<words[i][j]<<" "<<words[i-1][j]<<endl;
                if(m[words[i][j]]<m[words[i-1][j]] or (m[words[i][j]]==m[words[i-1][j]] and j==min(words[i].length(),words[i-1].length())-1 and  words[i].length()<words[i-1].length())){
                    return false;
                }
                
                if(m[words[i][j]]>m[words[i-1][j]])break;
            }
        }
        return true;
    }
};