class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
       for(int i=1;i<arr.size();i++){
           arr[i]+=arr[i-1];
       } 
        int count=0;
        if(arr[k-1]/k >=t)count++;
        int i=1,j=k;
        while(j<arr.size()){
            if((arr[j]-arr[i-1])/k>=t)count++;
            i++;
            j++;
        }
        return count;
    }
};