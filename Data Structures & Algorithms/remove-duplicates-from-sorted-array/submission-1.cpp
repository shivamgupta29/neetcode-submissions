class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> seen(nums.begin(), nums.end());
        int i=0;
        for(int num: seen){
            nums[i++] = num;
        } 
        return seen.size();
    }
};