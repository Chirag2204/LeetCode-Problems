class Solution
{
    public:
        bool solve(string &s1, string &s2, string &s3, int index1, int index2, int index3, vector<vector < int>> &dp)
        {
            if (index1 >= s1.size() && index2 >= s2.size() && index3 >= s3.size()) return true;
             if (index1 <= s1.size() && index2 <= s2.size() && dp[index1][index2] != -1) return dp[index1][index2];
            if (index1 < s1.size() && s1[index1] == s3[index3] && index2 < s2.size() && s2[index2] == s3[index3])
                return dp[index1][index2]= (solve(s1, s2, s3, index1 + 1, index2, index3 + 1, dp) || solve(s1, s2, s3, index1, index2 + 1, index3 + 1, dp));

            else if (index1 < s1.size() && s1[index1] == s3[index3])
                return dp[index1][index2]=  solve(s1, s2, s3, index1 + 1, index2, index3 + 1, dp);
            else if (index2 < s2.size() && s2[index2] == s3[index3])
                return dp[index1][index2]=  solve(s1, s2, s3, index1, index2 + 1, index3 + 1, dp);
            else return false;
        }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.size() != s1.size() + s2.size())
            return false;
        vector<vector < int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};