class Solution {
public:
    int n;
    vector<vector<int>> res;
    void solve(vector<int> &temp, int idx, vector<int>& nums){
        res.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(temp, i+1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> temp;
        solve(temp, 0, nums);
        return res;
    }
};
