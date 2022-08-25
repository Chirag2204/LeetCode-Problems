class Solution {
public:
    vector<int> getnextsmaller(vector<int> &nums){
        vector<int> ans(nums.size());
        stack<int> st;
        st.push(-1);
        for(int i=nums.size()-1;i>=0;i--){
           
           while( st.top()!=-1 and nums[st.top()]>=nums[i])st.pop();
           
           ans[i]=st.top();
           st.push(i);
          
        }
        return ans;
    }
    
     vector<int> getprevsmaller(vector<int> &nums){
        vector<int> ans(nums.size());
        stack<int> st;
        st.push(-1);
        for(int i=0;i<nums.size();i++){
           while( st.top()!=-1 and nums[st.top()]>=nums[i])st.pop();
           
           ans[i]=st.top();
           st.push(i);
          
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        
        next=getnextsmaller(heights);
        
        vector<int> prev(n);
        prev=getprevsmaller(heights);
        
        int ans=0;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)next[i]=n;
            int b=next[i]-prev[i]-1;
            
            ans=max(ans,l*b);
        }
        return ans;
    }
};