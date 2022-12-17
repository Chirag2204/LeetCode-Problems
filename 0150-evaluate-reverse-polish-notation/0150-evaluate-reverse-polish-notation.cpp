class Solution {
public:
    int mod=1e9+7;
    
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i][0]=='+'){
               int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push((num1+num2)%mod);
            }
            else if(tokens[i][0]=='-'){
                if(tokens[i].length()>1){
                   
                st.push(stoi(tokens[i]));
                }else{
                   int num1=st.top();
                   st.pop();
                   int num2=st.top();
                   st.pop();
                   st.push(num2-num1); 
                }
                
            }
            else if(tokens[i][0]=='*'){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push((long long)(num1)*(long long)(num2));
            }
            else if(tokens[i][0]=='/'){
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                st.push(num2/num1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return int(st.top());
    }
};