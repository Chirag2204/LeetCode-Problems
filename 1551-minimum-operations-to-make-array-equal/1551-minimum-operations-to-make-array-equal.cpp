class Solution {
public:
    int minOperations(int n) {
        
         int count=0;
        int mid=n%2==0? n : 2*(n/2)+1;
        for(int i=n/2;i<n;i++){
            count+=max(0,(2*i + 1)-mid);
        }
        return count;
    }
};