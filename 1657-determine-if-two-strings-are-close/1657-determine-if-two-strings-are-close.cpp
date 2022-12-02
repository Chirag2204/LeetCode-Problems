class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())return false;
        
        vector<int> nums1(26),nums2(26);
        
        for(char& c:word1)nums1[int(c)-97]++;
        for(char& c:word2)nums2[int(c)-97]++;
        
        for(int i=0;i<26;i++){
            if(nums1[i]==0 and nums2[i])return false;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        return nums1==nums2;
    }
};