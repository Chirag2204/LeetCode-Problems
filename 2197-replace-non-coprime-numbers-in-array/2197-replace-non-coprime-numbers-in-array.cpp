class Solution {
public:
    int gcd( int a, long long int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
 
    int lcm(int a, int b)
    {
        return (a / gcd(a, b)) * b;
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || gcd(st.top(),nums[i])==1){
                
                st.push(nums[i]);
            }else{
                int temp=lcm(st.top(),nums[i]);
                st.pop();
                while(!st.empty()){
                    if(gcd(st.top(),temp)==1)break;
                    temp=lcm(st.top(),temp);
                    st.pop();
                 } 
                
                st.push(temp);
           
         }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};