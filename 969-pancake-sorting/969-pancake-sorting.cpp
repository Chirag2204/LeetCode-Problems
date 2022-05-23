class Solution {
public:
   vector<int> pancakeSort(vector<int> A) {
        vector<int> ans;
        int x,i;
        for (x = A.size(); x > 0; --x) {
            for (i = 0; A[i] != x; ++i);
            reverse(A.begin(), A.begin() + i + 1);
            ans.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            ans.push_back(x);
        }
        return ans;
    }
};