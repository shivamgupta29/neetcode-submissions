class Solution {
public:
    bool palindrome(int l, int r, string &s){
        if(l>=r) return true;
        if(s[l] == s[r]){
            return palindrome(l+1, r-1, s);
        }
        return false;
    }
    int countSubstrings(string s) {
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
