class Solution {
public:
    vector<vector<int>> memo;
    bool palindrome(int l, int r, string &s){
        if(l>=r){
            return true;
        }
        if(memo[l][r] != -1) return memo[l][r];
        if(s[l] == s[r]){
            return palindrome(l+1, r-1, s);
        }
        return memo[l][r] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memo.resize(n+1, vector<int>(n+1, -1));
        string ans="";
        for(int l=0;l<s.length();l++){
            for(int r=l;r<s.length();r++){
                int len = r-l+1;
                if(palindrome(l, r, s)){
                    if(ans.length() < len){
                        ans = s.substr(l, r-l+1);
                    }
                }
            }
        }
        return ans;
    }
};
