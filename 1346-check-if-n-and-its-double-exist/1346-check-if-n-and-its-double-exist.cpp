class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(int& i:arr){
            m[i]++;
        }
        
        for(int &i:arr){
            if( m[2*i]>=1){
                if(i==0){
                    if(m[i]>1)return true;
                }
                else
                return true;
            }
        }
        return false;
    }
};