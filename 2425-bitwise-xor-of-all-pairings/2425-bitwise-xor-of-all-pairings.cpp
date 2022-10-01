class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0,xor2=0;
        for(int& i:nums1)xor1^=i;
        for(int& i:nums2)xor2^=i;
        cout<<xor1<<" "<<xor2<<endl;
        return (nums2.size()%2 * xor1)^(nums1.size()%2 * xor2);
    }
};