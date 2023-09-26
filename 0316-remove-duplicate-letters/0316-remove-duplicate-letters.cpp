class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> chars(26,0),vis(26,0);
        stack<char> st;
        
        for(char& c:s){
            chars[c-97]++;
        }
        
        for(int i=0;i<s.length();i++){
            chars[s[i]-97]--;//keeps count of remaining chars
            
            if(vis[s[i]-97])continue;
           
            while(!st.empty() and s[i]<st.top() and chars[st.top()-97]){
                vis[st.top()-97]=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-97]=1;
            
        }
        
        string ans="";
        while(!st.empty()){
            char c=st.top();
            st.pop();
            ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};