class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s=0,e=arr.size()-k;
        int mid=s+(e-s)/2;
        while(s<e){
            if(x-arr[mid]>arr[mid+k]-x){
                s=mid+1;
            }else e=mid;
            mid=s+(e-s)/2;
        }
        return vector<int>(arr.begin()+s,arr.begin()+s+k);
        
    }
};