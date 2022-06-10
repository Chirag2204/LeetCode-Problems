class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int maxlen=0,len=0;
        for(int i=33;i<127;i++){
            umap[char(i)]=-1;
        }
       umap[' ']=-1;
        
        for(int i=0;i<s.length();i++){
           if(umap[s[i]]==-1){
               umap[s[i]]=i;
               len++;
           }else{
               
               i=umap[s[i]];
               for(int i=33;i<127;i++){
            umap[char(i)]=-1;
        }
               umap[' ']=-1;
               len=0;
           }
            if(len>maxlen){
                maxlen=len;
            }
        }
        return maxlen;
    }
};