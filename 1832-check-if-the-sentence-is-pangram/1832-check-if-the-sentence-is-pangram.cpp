class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_map<char,int> umap;
        for(int i=0;i<s.length();i++){
            umap[s[i]]++;
        }
        for(int i=97;i<123;i++){
            if(!umap.count(char(i)))
                return false;
        }
        return true;
    }
};