class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int i=0,j=0;
        unordered_map<string,int> m;
        unordered_map<string,int> temp;
        for(string& word:words){
            m[word]++;
            temp[word]++;
        }
        vector<int> ans;
       
        int l=words[0].length();
        while(j<s.length()){
            string myword=s.substr(j,l);
            if(temp.count(myword) and temp[myword]!=0){
              
                j+=l;
                temp[myword]--;
                bool push=true;
                for(auto& x:temp){
                    if(x.second>0){
                        push=false;
                        break;
                    }
                }
                if(push){
                    ans.push_back(i);
                    i++;
                    j=i;
                    temp=m;
                }
            } else{
                
                i++;
                j=i;
                temp=m;
            }
        }
        return ans;
    }
};