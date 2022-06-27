class Solution {
public:
    int minPartitions(string n) {
       int max=0;
        for(int i=0;i<n.length();i++){
            if(max<int(n[i]-48)){
                max=n[i]-48;
            }
        }
        return max;
    }
};