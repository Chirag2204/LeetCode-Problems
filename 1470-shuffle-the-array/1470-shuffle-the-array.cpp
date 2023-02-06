class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> nums1(2*n);
        int count=0;
        for(int i=0;i<n;i++){
          nums1[count]=nums[i];
          count++;
            nums1[count]=nums[n+i];
            count++;
        }
        return nums1;
    }
};