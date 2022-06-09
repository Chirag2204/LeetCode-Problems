class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int p=1,q=numbers.size();
        while(numbers[p-1]+numbers[q-1]!=target){
             int sum=numbers[p-1]+numbers[q-1];
           if(sum>target)
               q--;
            else
                p++;
        }
        ans[0]=p;
        ans[1]=q;
        return ans;
    }
};