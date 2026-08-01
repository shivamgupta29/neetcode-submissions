class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int ans=0;
        int j=0;
        for(int i=0;i<s.length();i++){
            while(charSet.count(s[i])){
                charSet.erase(s[j]);
                j++;
            }
            charSet.insert(s[i]);
            ans = max(ans, i-j+1);
        } 
        return ans;
    }
};
