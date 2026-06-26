class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0;
        int j=0;
        bool turn=0;
        while(i<word1.length() && j<word2.length()){
            ans += word1[i++];
            ans += word2[j++];
        }
        ans += word1.substr(i);
        ans += word2.substr(j);
        return ans;
    }
};