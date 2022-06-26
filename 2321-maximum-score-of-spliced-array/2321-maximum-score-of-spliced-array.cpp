class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int diff1=0,diff2=0,temp1=0,temp2=0,sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
       int ans=max(sum1,sum2);
        for(int i=0;i<nums1.size();i++){
            temp1+=nums2[i]-nums1[i];
            temp2+=nums1[i]-nums2[i];
            
            diff1=max(diff1,temp1);
            diff2=max(diff2,temp2);
            
            if(temp1<0)temp1=0;
            if(temp2<0)temp2=0;
        }
         ans=max(ans,sum1+diff1);
         ans=max(ans,sum2+diff2);
        return ans;
    }
};