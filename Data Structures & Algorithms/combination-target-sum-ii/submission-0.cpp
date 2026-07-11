class Solution {
public:
    vector<vector<int>> ans;
    int T;
    void solve(vector<int>& candidates, vector<int> &temp, int sum, int s){
        if(sum > T) return;
        if(sum == T){
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<candidates.size();i++){
            if(i>s && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates, temp, sum + candidates[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        T = target;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, temp, 0, 0);
        return ans;
    }
};
