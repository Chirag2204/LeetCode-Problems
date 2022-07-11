class CustomStack {
public:
    stack<int> st;
    stack<int>st1;
    int mx;
    CustomStack(int maxSize) {
        mx=maxSize;
    }
    
    void push(int x) {
        if(st.size()<mx)st.push(x);
    }
    
    int pop() {
        if(st.empty())return -1;
        int t=st.top();
        st.pop();
        return t;
    }
    
    void increment(int k, int val) {
        while(!st.empty()){
            int t=st.top();
            st1.push(t);
            st.pop();
        }        
        while(!st1.empty()){
            int t=st1.top();
            if(k>0){
              t+=val;
                k--;
            }
            st.push(t);
            st1.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */