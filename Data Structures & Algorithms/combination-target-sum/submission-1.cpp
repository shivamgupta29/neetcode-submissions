class Solution {
public:
    vector<vector<int>> ans;
    int T;
    void solve(vector<int>& nums, vector<int> &temp, int sum, int s){
        if(sum > T) return;
        if(sum == T){
            ans.push_back(temp);
            return;
        }
        for(int i=s;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(nums, temp, sum + nums[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        T = target;
        vector<int> temp;
        solve(nums, temp, 0, 0);
        return ans;
    }
};
