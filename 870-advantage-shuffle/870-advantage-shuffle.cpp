class Solution {
public:
    //int bs(vector<int>& nums1,int& x){
        // int s=0;
        // int e=nums1.size()-1;
        // int ans=-1;
        // int mid=s+(e-s)/2;
        // while(s<=e){
        //     if(nums1[mid]>x){
        //         ans=mid;
        //         e=mid-1;
        //     }else s=mid+1;
        //     mid=s+(e-s)/2;
        // }
        // return ans;
    //}
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        multiset<int> s(nums1.begin(),nums1.end());
        // sort(nums1.begin(),nums1.end());
        // for(int i=0;i<nums2.size();i++){
        //    int x=bs(nums1,nums2[i]);
        //     if(x==-1){
        //         ans.push_back(nums1[0]);
        //         nums1.erase(nums1.begin());
        //     }else{
        //         ans.push_back(nums1[x]);
        //         if(x==nums1.size()-1)nums1.pop_back();
        //         else nums1.erase(nums1.begin()+x);
        //     }
        // }
        // // reverse(ans.begin(),ans.end());
        for(int i=0;i<nums2.size();i++){
           auto it=*s.rbegin()<=nums2[i]?s.begin():s.upper_bound(nums2[i]);
            ans[i]=*it;
            s.erase(it);
            }
        return ans;
    }
};