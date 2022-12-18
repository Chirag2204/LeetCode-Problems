class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
            vector<int> ans(temp.size(),0);
            stack<int> st;
        st.push(0);
        int count=0;
        for(int i=1;i<temp.size();i++){
            while(!st.empty() && temp[i]>temp[st.top()]){
               
       
                ans[st.top()]=i-st.top();
                st.pop();
            }
       
         
            st.push(i);
        }
        return ans;
    }
};