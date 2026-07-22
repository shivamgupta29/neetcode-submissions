class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length()==0 || text2.length()==0) return 0;
        if(text1 == text2) return text1.length();
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = (text1[0]==text2[0]) ? 1: 0;
        for(int i=1;i<m;i++){
            if(dp[i-1][0]==1) dp[i][0]=1;
            else{
                dp[i][0] = (text1[i]==text2[0]) ? 1: 0;
            }
        }
        for(int i=1;i<n;i++){
            if(dp[0][i-1]==1) dp[0][i]=1;
            else
                dp[0][i] = (text1[0]==text2[i]) ? 1: 0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
