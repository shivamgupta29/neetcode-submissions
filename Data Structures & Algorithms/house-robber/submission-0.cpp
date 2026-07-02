class Solution {
public:
    vector<int> mem;
    int solve(int i, vector<int>& nums){
        if(i>=nums.size()) return 0;
        if(mem[i] != -1) return mem[i];
        int steal = nums[i] + solve(i+2, nums);
        int leave = solve(i+1, nums);
        return mem[i] = max(steal, leave);
    }
    int rob(vector<int>& nums) {
        mem.resize(nums.size(), -1);
        return solve(0, nums);
    }
};
