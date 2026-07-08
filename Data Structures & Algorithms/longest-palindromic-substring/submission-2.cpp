class Solution {
public:
    bool palindrome(int l, int r, string &s){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
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
