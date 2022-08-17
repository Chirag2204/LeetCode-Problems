class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int count=0;
        unordered_map<string,int> umap;
        vector<string> letters{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++){
            string mystring="";
            for(int j=0;j<words[i].length();j++){
              mystring.append(letters[int(words[i][j])-97]);
                
            }
            if(!umap.count(mystring)){
                umap[mystring]=1;
                count++;
            }
        }
        return count;
    }
};