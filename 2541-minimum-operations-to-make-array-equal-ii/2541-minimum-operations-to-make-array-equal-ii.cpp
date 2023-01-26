class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0)
            if(nums1==nums2)return 0;
            else return -1;
        long long inc=0,dec=0;
        for(int i=0;i<nums1.size();i++){
           if(nums1[i]>nums2[i]){
               if((nums1[i]-nums2[i])%k!=0)return -1;
               dec+=(nums1[i]-nums2[i])/k;
           }
            if(nums1[i]<nums2[i]){
               if((nums2[i]-nums1[i])%k!=0)return -1;
               inc+=(nums2[i]-nums1[i])/k;
           }
           
        }
         if(inc!=dec)return -1;
            return inc;
    }
};