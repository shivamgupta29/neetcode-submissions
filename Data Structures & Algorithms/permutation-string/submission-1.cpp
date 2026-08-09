class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(char c: s1){
            freq[c-'a']++;
        }
        vector<int> freq2(26, 0);
        int start=0;
        for(int i=0;i<s2.length();i++){    
            freq2[s2[i]-'a']++;
            int len = i-start+1;
            if(len > s1.length()){
                freq2[s2[start]-'a']--;
                start++;
            }
            if(freq == freq2){
                return true;
            }
        }
        return false;
    }
};
