class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums, 0, sub, ans);
        return ans;
    }
    void solve(const vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
        if(i >= nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(nums, i+1, subset, res);
        subset.pop_back();
        solve(nums, i+1, subset, res);
    }
};
