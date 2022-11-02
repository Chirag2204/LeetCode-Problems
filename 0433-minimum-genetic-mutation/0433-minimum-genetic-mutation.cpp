class Solution {
public:
    vector<int> arr{'A','C','G','T'};
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st;
        for(string& s:bank)st.insert(s);
        
        int ans=1e9;
        
        queue<pair<string,int>> q;
        q.push({start,0});
        while(!q.empty()){
            string str=q.front().first;
            int dist=q.front().second;
            
            q.pop();
            if(str==end)ans=min(ans,dist);
            
            for(int i=0;i<str.length();i++){
                string temp=str;
                for(int j=0;j<4;j++){
                    temp[i]=arr[j];
                    if(st.count(temp)){
                        q.push({temp,dist+1});
                        st.erase(temp);
                    }
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;
        
    }
};