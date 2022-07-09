class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),mysort);
        return nums[k-1];
    }
    static bool mysort(string& a,string& b){
        if(a.length()==b.length())return a>b;
        return a.length()>b.length();
    }
};