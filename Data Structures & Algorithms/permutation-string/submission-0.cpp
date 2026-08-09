class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(char c: s1){
            freq[c-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            vector<int> freq2(26, 0);
            for(int j=i;j<s2.length();j++){
                freq2[s2[j]-'a']++;
                int len = j-i+1;
                if(len != s1.length()){
                    continue;
                }
                if(freq == freq2){
                    return true;
                }
            }
        }
        return false;
    }
};
