class Solution {
public:
    int minimumSum(int n, int k) {
        
        set<int> st;
        int i=1,ans=0;
        while(n>0){
            if(!st.count(k-i)){
                n--;
                ans+=i;
                st.insert(i);
            }
            i++;
        }
        return ans;
    }
};