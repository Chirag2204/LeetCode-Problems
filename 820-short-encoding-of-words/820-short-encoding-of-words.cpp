class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),mysort);
        for(int i=0;i<words.size()-1;i++){
            if(words[i]==words[i+1]){
                words.erase(words.begin()+i);
                i--;
            }
            else{
                int n=words[i].length();
            for(int j=i+1;j<words.size();j++){
                int l=words[j].length();
                if(words[i].substr(n-l,l)==words[j]){
                    words.erase(words.begin()+j);
                    j--;
                }
            }
            }
            
            
        }
        int count=words.size();
            for(int i=0;i<words.size();i++){
                count+=words[i].length();
            }
            return count;
       
    }
     static bool mysort(string& a,string& b){
            return a.length()>b.length();
        }
};