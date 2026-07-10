class Solution {
public:
    int roblineear(vector<int> &vec, int i, unordered_map<int,int> &mem){
        if(i>=vec.size()) return 0;
        if(mem.count(i)) return mem[i];
        int skip = roblineear(vec, i+1, mem);
        int steal = vec[i] + roblineear(vec, i+2, mem);
        return mem[i] = max(skip, steal);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> slice1(nums.begin(), nums.end() - 1);
        vector<int> slice2(nums.begin()+1, nums.end());
        unordered_map<int,int> mem1;
        unordered_map<int,int> mem2;
        int rob1 = roblineear(slice1, 0, mem1);
        int rob2 = roblineear(slice2, 0, mem2);
        return max(rob1,rob2);
    }
};
