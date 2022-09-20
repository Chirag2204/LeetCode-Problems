class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string& s: wordList)st.insert(s);
        
        queue<pair<string,int>> q;//string at dist from beg
        
        int ans=INT_MAX;
        
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int dist=q.front().second;
            
            q.pop();
            if(s==endWord)ans=min(ans,dist);
            
            for(int i=0;i<s.length();i++){
                string temp=s;
                for(int j=0;j<26;j++){
                    temp[i]=char(j+97);
                    if(st.count(temp)){
                        st.erase(temp);
                        q.push({temp,dist+1});
                    }
                }
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;
    }
};