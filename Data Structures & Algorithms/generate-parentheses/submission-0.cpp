class Solution {
public:
    vector<string> ans;
    void backtrack(string &curr, int n, int open, int end){
        if(open==n && end==n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            backtrack(curr, n, open+1, end);
            curr.pop_back();
        }
        if(end<open){
            curr.push_back(')');
            backtrack(curr, n, open, end+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        backtrack(curr, n, 0, 0);
        return ans;
    }
};
