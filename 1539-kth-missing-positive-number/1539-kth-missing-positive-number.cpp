class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=1;
        if(arr[0]-prev<k){
            k-=(arr[0]-prev);
        }else return k;
        prev=arr[0];
        for(int i=1;i<arr.size();i++){
            // cout<<i<<" "<<k<<endl;
            if(arr[i]-prev-1<k){
                k-=(arr[i]-prev-1);
                prev=arr[i];
            }
            else{
                return arr[i-1]+k;
            }
        }
        return arr[arr.size()-1]+k;
    }
};