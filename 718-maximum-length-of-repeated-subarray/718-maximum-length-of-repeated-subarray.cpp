class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans1=0;
        for(int i=0;i<nums1.size();i++){
            int k=i,count=0;
            for(int j=0;j<nums2.size();j++){
                if(k<nums1.size() and nums1[k]==nums2[j]){
                    count++;
                    k++;
                }
                else{
                    k=i;
                   
                     count=0;
                    if(nums1[k]==nums2[j]){
                    count++;
                    k++;
                  }
                } 
                 ans1=max(ans1,count);
            }
        }
        int ans2=0;
        for(int i=0;i<nums2.size();i++){
            int k=i,count=0;
            for(int j=0;j<nums1.size();j++){
                if(k<nums2.size() and nums2[k]==nums1[j]){
                    count++;
                    k++;
                }
                else{
                    k=i;
                   
                     count=0;
                    if(nums2[k]==nums1[j]){
                    count++;
                    k++;
                  }
                } 
                 ans2=max(ans2,count);
            }
        }
        
        return max(ans1,ans2);
    }
};