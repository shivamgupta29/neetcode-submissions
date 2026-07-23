class Solution {
public:
    int numDistinct(string s, string t) {
        if(s == t) return 1;
        if(s.length() < t.length()) return 0;
        int M=s.length();
        int N=t.length();
        vector<vector<unsigned long long>> dp(M+1, vector<unsigned long long>(N+1, 0));
        // Empty string t can always be formed in exactly one way.
        for (int i = 0; i <= M; i++) {
            dp[i][0] = 1;
        }

        // Non-empty t cannot be formed from an empty s.
        for (int j = 1; j <= N; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[M][N];
    }
};
