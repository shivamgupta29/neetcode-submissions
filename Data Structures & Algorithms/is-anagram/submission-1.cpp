class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> sfreq;
        unordered_map<char, int> tfreq;
        for(int i=0;i<s.length();i++){
            sfreq[s[i]]++;
            tfreq[t[i]]++;
        }
        for(auto& [c, f]: sfreq){
            if(tfreq[c] != f){
                return false;
            }
        }
        return true;
    }
};
