class Solution {
public:
    vector<vector<int>> memo;
    bool palindrome(int l, int r, string &s){
        if(l>=r) return memo[l][r] = 1;
        if(memo[l][r]!=-1) return memo[l][r];
        if(s[l] == s[r]){
            return palindrome(l+1, r-1, s);
        }
        return memo[l][r] = 0;
    }
    int countSubstrings(string s) {
        int n = s.length();
        memo.resize(n+1, vector<int>(n+1, -1));
        int cnt=0;
        for(int l=0;l<s.length();l++){
            for(int r=l;r<s.length();r++){
                if(palindrome(l, r, s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
