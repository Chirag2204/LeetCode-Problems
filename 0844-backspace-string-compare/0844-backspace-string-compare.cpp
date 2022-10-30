class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char> s1;
        stack<char> t1;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }else{
                s1.push(s[i]);
            }
        }
        
        for(int i=0;i<t.length();i++){
            //cout<<t[i]<<"->";
            if(t[i]=='#'){
                if(!t1.empty())t1.pop();
            }else{
                t1.push(t[i]);
            }
        }
        s.clear();
        t.clear();
        while(!s1.empty()){
            s.push_back(s1.top());
            s1.pop();
        }
        
        while(!t1.empty()){
            t.push_back(t1.top());
            t1.pop();
        }
       
        return s==t;
    }
};