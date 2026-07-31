class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int i=1;
        while(numSet.find(i)!=numSet.end()){
            i++;
        }
        return i; 
    }
};