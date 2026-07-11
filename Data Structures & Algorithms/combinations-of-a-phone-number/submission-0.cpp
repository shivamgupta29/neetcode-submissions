class Solution {
public:
    vector<string> ans;
    void solve(int i, string &current, string digits, vector<string> phone){
        if(i == digits.length()){
            ans.push_back(current);
            return;
        }
        string letters = phone[digits[i]-'0'];
        for(char c: letters){
            current.push_back(c);
            solve(i+1, current, digits, phone);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> phone = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string current;
        solve(0, current, digits, phone);
        return ans;
    }
};
