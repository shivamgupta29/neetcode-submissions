class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> freqT(128, 0);
        vector<int> freqS(128, 0);

        for (char c : t) {
            freqT[c]++;
        }

        int required = 0;

        for (int i = 0; i < 128; i++) {
            if (freqT[i] > 0)
                required++;
        }

        int formed = 0;
        int start = 0;

        int shortest = INT_MAX;
        int bestStart = 0;

        for (int end = 0; end < s.size(); end++) {

            char c = s[end];
            freqS[c]++;

            if (freqT[c] > 0 && freqS[c] == freqT[c]) {
                formed++;
            }

            while (formed == required) {

                int len = end - start + 1;

                if (len < shortest) {
                    shortest = len;
                    bestStart = start;
                }

                char left = s[start];
                freqS[left]--;

                // We just lost a required character
                if (freqT[left] > 0 && freqS[left] < freqT[left]) {
                    formed--;
                }

                start++;
            }
        }

        if (shortest == INT_MAX)
            return "";

        return s.substr(bestStart, shortest);
    }
};
