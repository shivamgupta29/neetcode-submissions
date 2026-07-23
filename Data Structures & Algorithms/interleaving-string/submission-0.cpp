class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s1, string &s2, string &s3, int i, int j) {

        if (i == s1.length() && j == s2.length())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        int k = i + j;

        bool res = false;

        if (i < s1.length() && s1[i] == s3[k]) {
            res = res || solve(s1, s2, s3, i + 1, j);
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            res = res || solve(s1, s2, s3, i, j + 1);
        }

        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;

        dp.assign(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return solve(s1, s2, s3, 0, 0);
    }
};
