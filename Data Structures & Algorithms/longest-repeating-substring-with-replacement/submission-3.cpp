class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0;
        vector<int> hash(26, 0);
        int maxF=0;
        int start=0;
        for(int i=0;i<s.length();i++){
            hash[s[i]-'A']++;
            maxF = max(maxF, hash[s[i]-'A']);
            int len = i-start+1;
            int changes = len-maxF;
            if(changes <= k){
                maxlen = max(maxlen, i-start+1);
            }else{
                hash[s[start]-'A']--;
                for(int j=0;j<26;j++){
                    maxF = max(maxF, hash[j]);
                }
                start++;
            }
        }
        return maxlen;
    }
};
