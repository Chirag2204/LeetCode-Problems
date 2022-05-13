class Solution {
public:
    static int getPower(int n){
        int count=0;
        while(n!=1){
            if(n%2)n=n*3 + 1;
            else n=n/2;
            count++;
        }
        return count;
    }
    int getKth(int lo, int hi, int k) {
       vector<int> nums;
        for(int i=lo;i<=hi;i++){
            nums.push_back(i);
        }
        sort(nums.begin(),nums.end(),sortbypower);
        return nums[k-1];
    }
    static bool sortbypower(int a,int b){
        if(getPower(a)==getPower(b))return a<b;
        return getPower(a)<getPower(b);
    }
};