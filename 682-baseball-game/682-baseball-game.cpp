class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
       for(auto s:ops){
           if(s[0]=='C'){
               st.pop();
           }
           else if(s[0]=='+'){
               int temp=st.top();
               st.pop();
               int temp2=temp+st.top();
               st.push(temp);
               st.push(temp2);
           }
           else if(s[0]=='D'){
               int top=st.top();
               st.push(2*top);
           }
           else{
               stringstream str(s);
               int x;
               str>>x;
               cout<<x<<endl;
               st.push(x);
           }
       }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};