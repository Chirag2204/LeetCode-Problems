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
    
    //get previous index at which value from index i is smaller because upto that index we can form a rectangle of height heights[i]
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
            int l=heights[i];//height of rectangle
            if(next[i]==-1)next[i]=n;
            int b=next[i]-prev[i]-1;//width of rectangle
            
            ans=max(ans,l*b);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& M) {
        int n=M.size(),m=M[0].size();
         vector<int> lvl(m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='0')lvl[j]=0;
                else lvl[j]++;
                
            }
           ans=max(ans,largestRectangleArea(lvl));
        }
        return ans;
    }
};